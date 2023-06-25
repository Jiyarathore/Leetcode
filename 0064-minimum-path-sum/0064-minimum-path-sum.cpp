class Solution {
public:
    
//     easy sol
//     int minPathSum(vector<vector<int>>& grid) {
//         int rows = grid.size();
        
//         if(rows==0) 
//             return 0;
//         int cols= grid[0].size();
//         vector<vector<int>>dp(rows,vector<int>(cols,0));
//         int i,j;
        
//         dp[0][0] = grid[0][0];
        
//         for(int i=1;i<cols;i++)
//             dp[0][i] = dp[0][i-1] + grid[0][i];
        
//         for(int i=1;i<rows;i++)
//             dp[i][0]=dp[i-1][0] + grid[i][0];
        
//         for(int i=1;i<rows;i++){
//             for(j=1;j<cols;j++){
//                 dp[i][j]= grid[i][j] + min(dp[i-1][j] ,dp[i][j-1]);
//             }
//         }
//         return dp[rows-1][cols-1];
//     }
    
//     Memorization 
    
    int minSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        
        if(i<0 || j<0) return 1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=grid[i][j]+ minSum(i-1,j,grid,dp);
        int left=grid[i][j] + minSum(i,j-1,grid,dp);
        
        return dp[i][j]=min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return minSum(n-1,m-1,grid,dp);
    }
    
};