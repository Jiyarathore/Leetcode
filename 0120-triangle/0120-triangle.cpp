class Solution {
public:
    
//     Memorixation
//     int minPath(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(i==n-1) return triangle[i][j];
        
//         int dn=triangle[i][j] + minPath(i+1,j,triangle,n,dp);
//         int dg=triangle[i][j] + minPath(i+1,j+1,triangle,n,dp);
        
//         return dp[i][j]=min(dn,dg);
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return minPath(0,0,triangle,n,dp);
//     }
    
//     Tabulation
    
      int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
          
          for(int j=0;j<n;j++){
              dp[n-1][j]=triangle[n-1][j];
          }
          
          for(int i=n-2;i>=0;i--){
              for(int j=i;j>=0;j--){
                  int dn=triangle[i][j] + dp[i+1][j];
                  int dg=triangle[i][j] + dp[i+1][j+1];
                  
                  dp[i][j]=min(dn,dg);
              }
          }
          return dp[0][0];
      }
      };