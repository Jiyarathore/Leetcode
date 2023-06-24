class Solution {
public:
    
//     Memorization Method gives runtime
    
//     Tabulation Method
    
//     int solveUtil(int n, vector<int>& arr, vector<int>& dp){
//     dp[0]=arr[0];
        
//         for(int i=1;i<n;i++){
//             int pick=arr[i];
//             if(i>1)
//                 pick+=dp[i-2];
//             int nonPick=0 + dp[i-1];
            
//             dp[i]=max(pick,nonPick);
//         }
//     return dp[n-1];
// }
    
//     int rob(vector<int>& arr) {
//         int n=arr.size();
//         vector<int> dp(n,-1);
//         return solveUtil(n, arr, dp);
//     }

    
//     Space OPtimization
    
    int rob(vector<int>&arr){
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)
                pick+=prev2;
            int nonPick=0 + prev;
            
            int cur_i=max(pick,nonPick);
            prev2=prev;
            prev=cur_i;
        }
        return prev;
    }
};