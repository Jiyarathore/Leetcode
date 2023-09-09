class Solution {
public:
//     Memoization
//     int lcsUtil(string& s1, string& s2, int ind1,int ind2, vector<vector<int>>dp){
//         if(ind1<0 || ind2<0) return 0;
        
//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
//         if(s1[ind1]==s2[ind2])
//             return dp[ind1][ind2]=1+lcsUtil(s1,s2,ind1-1,ind2-1,dp);
        
//         else
//             return dp[ind1][ind2]=0+max(lcsUtil(s1,s2,ind1,ind2-1,dp) , lcsUtil(s1,s2,ind1-1,ind2,dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
        
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return lcsUtil(text1,text2,n-1,m-1,dp);
//     }
    
//     Tabulation
    
//     int longestCommonSubsequence(string s1, string s2) {
//         int n=s1.size();
//         int m=s2.size();
        
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         for(int i=0;i<=n;i++) dp[i][0]=0;
        
//         for(int j=0;j<=m;j++) dp[0][j]=0;
        
//         for(int ind1=1;ind1<=n;ind1++){
//             for(int ind2=1;ind2<=m;ind2++){
//                 if(s1[ind1-1]==s2[ind2-1])
//                     dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                
//                 else
//                     dp[ind1][ind2]=0+max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
//             }
//         }
//         return dp[n][m];
//     }
    
//     Space Optimization
    
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        vector<int>prev(m+1,0), cur(m+1,0);
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    cur[ind2]=1+prev[ind2-1];
                
                else
                    cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        
        return prev[m];
    }
    
    
    
};