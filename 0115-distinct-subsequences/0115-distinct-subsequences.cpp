class Solution {
public:
    const int prime = 1e9 + 7;
    
//     Mmeorization Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(N+M)

//     int countUtil(string s1, string s2,int ind1,int ind2, vector<vector<int>>&dp){
//         if(ind2<0) return 1;
        
//         if(ind1<0) return 0;
        
//         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
//         int result=0;
        
//         if(s1[ind1]==s2[ind2]){
//             int leaveOne=countUtil(s1,s2,ind1-1,ind2-1,dp);
//             int stay=countUtil(s1,s2,ind1-1,ind2,dp);
            
//             result=(leaveOne+stay)%prime;
//         }
//         else{
//             result=countUtil(s1,s2,ind1-1,ind2,dp);
//         }
//         dp[ind1][ind2]=result;
//         return result;
//     }
    
//     int numDistinct(string s, string t) {
//         int ls=s.size(), lt=t.size();
//         vector<vector<int>>dp(ls,vector<int>(lt,-1));
//         return countUtil(s, t, ls-1, lt-1,dp);
//     }
    
     int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         
         for(int i=0;i<=n;i++){
             dp[i][0]=1;
         }
         for(int i=1;i<=m;i++){
             dp[0][i]=0;
         }
         
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 if(s[i-1]==t[j-1]){
                     dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%prime;
                 }
                 else{
                     dp[i][j]=dp[i-1][j];
                 }
             }
         }
         return dp[n][m];
     }
};