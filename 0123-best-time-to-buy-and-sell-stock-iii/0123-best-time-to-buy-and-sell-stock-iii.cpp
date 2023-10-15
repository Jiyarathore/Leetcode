class Solution {
public:
    
//     mmorization Time Complexity: O(N*2*3) 

// Space Complexity: O(N*2*3) + O(N)
    
//     int getAns(vector<int>&arr, int n, int ind, int buy, int cap,vector<vector<vector<int>>>dp){
//         if(ind==n|| cap==0) return 0;
        
//         if(dp[ind][buy][cap]!=-1)
//             return dp[ind][buy][cap];
        
//         int profit;
        
//         if(buy==0){
//             profit=max(0+getAns(arr,n,ind+1, 0, cap, dp), -arr[ind] + getAns(arr, n, ind+1, 1, cap, dp));
//         }
        
//         if(buy==1){
//             profit=max(0+getAns(arr,n,ind+1,1,cap,dp), arr[ind]+getAns(arr,n,ind+1,0,cap-1,dp));
//         }
        
//         return dp[ind][buy][cap]=profit;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        
//         return getAns(prices, n,0, 0, 2, dp);
//     }
    
     int maxProfit(vector<int>& Arr) {
         
         int n=Arr.size();
        // Creating a 3D DP array of size [n+1][2][3] initialized to 0
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case: dp array is already initialized to 0, covering the base case.

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                           -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                           Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
    return dp[0][0][2];
         
     }
};