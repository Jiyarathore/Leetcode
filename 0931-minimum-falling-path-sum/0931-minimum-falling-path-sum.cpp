class Solution {
public:
    
//     /memeorixation
    
//     int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix, 
// vector<vector<int> > &dp){
    
//     // Base Conditions
//     if(j<0 || j>=m)
//         return 1e9;
//     if(i==0)
//         return matrix[0][j];
    
//     if(dp[i][j]!=-1) return dp[i][j];
    
//     int up = matrix[i][j] + getMaxUtil(i-1,j,m,matrix,dp);
//     int leftDiagonal = matrix[i][j] + getMaxUtil(i-1,j-1,m,matrix,dp);
//     int rightDiagonal = matrix[i][j] + getMaxUtil(i-1,j+1,m,matrix,dp);
    
//     return dp[i][j]= min(up,min(leftDiagonal,rightDiagonal));
    
// }
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//     int m = matrix[0].size();
    
//     vector<vector<int>> dp(n,vector<int>(m,-1));
    
//     int mini = INT_MAX;
    
//     for(int j=0; j<m;j++){
//         int ans = getMaxUtil(n-1,j,m,matrix,dp);
//         mini = min(mini,ans);
//     }
    
//     return mini;
//     }
    
//     Tabultaion
    
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//     int m = matrix[0].size();
    
//     vector<vector<int>> dp(n,vector<int>(m,0));
        
//         for(int j=0;j<m;j++){
//             dp[0][j]=matrix[0][j];
//         }
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<m;j++){
//                 int up=matrix[i][j] + dp[i-1][j];
                
//                 int leftdg=matrix[i][j];
//                 if(j-1>=0) leftdg+=dp[i-1][j-1];
//                 else leftdg+=1e9;
                
//                 int rightdg=matrix[i][j];
//                 if(j+1<m) rightdg+=dp[i-1][j+1];
//                 else rightdg+=1e9;
                
//                 dp[i][j]=min(up,min(rightdg,leftdg));
//             }
//         }
//         int mini = INT_MAX;
    
//     for(int j=0; j<m;j++){
        
//         mini = min(mini,dp[n-1][j]);
//     }
    
//     return mini;
//     }
    
    
//     space opmitimazarion
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
    int m = matrix[0].size();
        
        vector<int>prev(m,0),cur(m,0);
        
        for(int j=0;j<m;j++){
            prev[j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j] + prev[j];
                
                int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += prev[j-1];
            else leftDiagonal += 1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += prev[j+1];
            else rightDiagonal += 1e9;
                
                cur[j]=min(up,min(leftDiagonal, rightDiagonal));
            }
            prev=cur;
        }
        
          int mini = INT_MAX;
    
    for(int j=0; j<m;j++){
        
        mini = min(mini,prev[j]);
    }
    
    return mini;
        }
};