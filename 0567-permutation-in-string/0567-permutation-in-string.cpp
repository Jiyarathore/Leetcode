class Solution {
public:
    
    bool areVectorsEqual(vector<int>freqs1,vector<int>freqs2){
        for(int i=0;i<26;i++){
            if(freqs1[i]!=freqs2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        
        vector<int>freqs1(26,0);
        for(char c:s1){
            freqs1[c-'a']++;
        }
        vector<int>freqs2(26,0);
        int i=0,j=0;
        
        while(j<s2.size()){
            freqs2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freqs1,freqs2)) return true;
            }
            
            if(j-i+1<s1.size()){
                j++;
            }
            else{
                freqs2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};