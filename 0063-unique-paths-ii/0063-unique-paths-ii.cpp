class Solution {
public:
//     Before solution
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        
        bool flag=false;
        
        for(int i=0;i<cols;i++){
            if(flag || obstacleGrid[0][i]==1){
                flag=true;
                dp[0][i]=0;
            }
            else{
                dp[0][i]=1;
            }
        }
        
        flag=false;
        for(int i=0;i<rows;i++){
            if(flag || obstacleGrid[i][0]==1){
                flag=true;
                dp[i][0]=0;
            }
            else dp[i][0]=1;
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
    
    
//     Memorization Method
    
//    int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int> > 
// &dp) {
//   if(i>0 && j>0 && maze[i][j]==-1) return 0; 
//   if(i==0 && j == 0)
//     return 1;
//   if(i<0 || j<0)
//     return 0;
//   if(dp[i][j]!=-1) return dp[i][j];
    
//   int up = mazeObstaclesUtil(i-1,j,maze,dp);
//   int left = mazeObstaclesUtil(i,j-1,maze,dp);
  
//   return dp[i][j] = up+left;
  
// }
    
//     Tabulation 
    
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
//          int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//        vector<vector<int> > dp(n,vector<int>(m,-1));
//    for(int i=0; i<n ;i++){
//       for(int j=0; j<m; j++){
          
//           //base conditions
//           if(i>0 && j>0 && obstacleGrid[i][j]==1){
//             dp[i][j]=0;
//             continue;
//           }
//           if(i==0 && j==0){
//               dp[i][j]=1;
//               continue;
//           }
          
//           int up=0;
//           int left = 0;
          
//           if(i>0) 
//             up = dp[i-1][j];
//           if(j>0)
//             left = dp[i][j-1];
            
//           dp[i][j] = up+left;
//       }
       
//     }
//          return dp[n-1][m-1];
//     }
    
};