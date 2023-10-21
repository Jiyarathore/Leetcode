class Solution {
public:
    
    bool checkPossible(string &s1, string &s2){
        if(s1.size()!=s2.size()+1) return false;
        
        int first=0,second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else first++;
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    
//    bool comp(string& s1, string& s2){
//     return s1.size() < s2.size();
// }
    
    int longestStrChain(vector<string>& words) {
        
       
    sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        
        for(int i=0;i<n;i++){
            
            for(int prev=0;prev<i;prev++){
                if(checkPossible(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};