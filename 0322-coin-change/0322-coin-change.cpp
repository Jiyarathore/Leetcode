class Solution {
public:
//     Memorization
    
//     int coinChangeUtil(vector<int>&arr, int ind, int T, vector<vector<int>>dp){
//         if(ind==0){
//             if(T%arr[0]==0) return T/arr[0];
//             else return 1e9;
//         }
        
//         if(dp[ind][T]!=-1) return dp[ind][T];
        
//         int notTaken=0+coinChangeUtil(arr,ind-1,T,dp);
        
//         int taken=1e9;
//         if(arr[ind]<=T){
//             taken=1+coinChangeUtil(arr,ind,T-arr[ind],dp);
//         }
//         return dp[ind][T]=min(taken,notTaken);
//     }
    
//     int coinChange(vector<int>& coins, int T) {
//         int n=coins.size();
        
//         vector<vector<int>>dp(n,vector<int>(T+1,-1));
        
//         int ans=coinChangeUtil(coins,n-1,T,dp);
//         if(ans>=1e9) return -1;
//         return ans;
//     }
    
//     Tabulation
     int coinChange(vector<int>& arr, int T){
         int n=arr.size();
         
         vector<vector<int>>dp(n,vector<int>(T+1,0));
         
         for(int i=0;i<=T;i++){
             if(i%arr[0]==0){
                 dp[0][i]=i/arr[0];
             }
             else dp[0][i]=1e9;
         }
         
         for(int ind=1;ind<n;ind++){
             for(int target=0;target<=T;target++){
                 int notTake=0+dp[ind-1][target];
                 
                 int take=1e9;
                 
                 if(arr[ind]<=target) take=1+dp[ind][target-arr[ind]];
                 
                 dp[ind][target]=min(take,notTake);
             }
         }
         int ans=dp[n-1][T];
         if(ans>=1e9) return -1;
         return ans;
     }
};