class Solution {
public:
//     easy solution
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,1));
        
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
    
//     Memorization
    
//     int countWays(int i,int j,vector<vector<int>> &dp){
//         if(i==0 && j==0)
//             return 1;
//         if(i<0 || j<0)
//             return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int up = countWays(i-1,j,dp);
//         int left =  countWays(i,j-1,dp);
        
//         return dp[i][j] = up+left;
//     }
    
//     int uniquePaths(int m,int n){
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return countWays(m-1,n-1,dp);
//     }
    
//     Tabulation
    
//     int CountWays(int m,int n, vector<vector<int>>&dp){
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0){
//                     dp[i][j]=1;
//                     continue;
//                 }
//                 int up=0;
//                 int left=0;
//                 if(i>0)
//                     up=dp[i-1][j];
//                 if(j>0)
//                     left=dp[i][j-1];
                
//                 dp[i][j]=up+left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
    
//     int uniquePaths(int m,int n){
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return CountWays(m,n,dp);
//     }
    
//     OPtimization
    
     int uniquePaths(int m,int n){
         vector<int>prev(n,0);
         for(int i=0;i<m;i++){
             vector<int>temp(n,0);
             for(int j=0;j<n;j++){
                 if(i==0 && j==0){
                     temp[j]=1;
                     continue;
                 }
                 int up=0;
                 int left=0;
                 
                 if(i>0){
                     up=prev[j];
                 }
                 if(j>0){
                     left=temp[j-1];
                 }
                 temp[j]=up+left;
             }
             prev=temp;
         }
         return prev[n-1];
     }
};