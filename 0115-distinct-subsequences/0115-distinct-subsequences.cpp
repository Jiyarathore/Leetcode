class Solution {
public:
    const int prime = 1e9 + 7;
    
    int countUtil(string s1, string s2,int ind1,int ind2, vector<vector<int>>&dp){
        if(ind2<0) return 1;
        
        if(ind1<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        int result=0;
        
        if(s1[ind1]==s2[ind2]){
            int leaveOne=countUtil(s1,s2,ind1-1,ind2-1,dp);
            int stay=countUtil(s1,s2,ind1-1,ind2,dp);
            
            result=(leaveOne+stay)%prime;
        }
        else{
            result=countUtil(s1,s2,ind1-1,ind2,dp);
        }
        dp[ind1][ind2]=result;
        return result;
    }
    
    int numDistinct(string s, string t) {
        int ls=s.size(), lt=t.size();
        vector<vector<int>>dp(ls,vector<int>(lt,-1));
        return countUtil(s, t, ls-1, lt-1,dp);
    }
};