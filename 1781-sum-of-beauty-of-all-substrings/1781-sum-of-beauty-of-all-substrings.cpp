class Solution {
public:
    
    int beauty(vector<int>&v){
        int maxfreq=-1;
        int minfreq=1e9;
        for(int i=0;i<26;i++){
            maxfreq=max(maxfreq,v[i]);
            if(v[i]>=1){
                minfreq=min(minfreq,v[i]);
            }
        }
        return maxfreq-minfreq;
    }
    
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
            vector<int>v(26,0);
            for(int j=i;j<s.size();j++){
                v[s[j]-'a']++;
                res=res+beauty(v);
            }
        }
        return res;
    }
};