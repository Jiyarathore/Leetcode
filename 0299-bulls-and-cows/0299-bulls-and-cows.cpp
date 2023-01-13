class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        // int x=0;
        unordered_map<char,int>m1,m2;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                m1[secret[i]]++;
                m2[guess[i]]++;
            }
        }
        for(auto i:m1){
            if(m2.find(i.first)!=m2.end()){
            cows+=min(i.second,m2[i.first]);    
            }
            
        }
        
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};