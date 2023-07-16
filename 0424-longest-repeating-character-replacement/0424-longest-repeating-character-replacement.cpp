class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int>m;
        int n=s.size();
        int i=0,j=0;
        int maxi=INT_MIN;
        int ans=0;
        while(j<n){
            m[s[j]]++;
            maxi=max(maxi,m[s[j]]);
            
            if((j-i+1)-maxi>k){
                m[s[i]]--;
                i++;
            }
            
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};