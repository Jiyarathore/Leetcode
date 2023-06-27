class Solution {
public:
    int longestPalindrome(string s) {
       map<char,int>m;
        int ans=0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m[s[i]]%2==0){
                ans+=m[s[i]];
                m[s[i]]=0;
            }
        }
        
        for(auto i:m){
            if(i.second%2!=0){
                ans++;
                break;
            }
        }
        return ans;
    }
};