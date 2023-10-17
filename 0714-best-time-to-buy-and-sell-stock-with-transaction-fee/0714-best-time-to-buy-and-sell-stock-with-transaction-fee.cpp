class Solution {
public:
    int getAns(vector<int> &Arr, int ind, int buy, int n, int fee, vector<vector<int>> &dp) {
    
    if (ind == n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, fee, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, fee, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, fee, dp), Arr[ind] - fee + getAns(Arr, ind + 1, 0, n, fee, dp));
    }
    
    // Store the computed profit in the DP array
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
         vector<vector<int>> dp(n, vector<int>(2, -1));
    
    if (n == 0) return 0; // Edge case: No stocks to trade.
    
    int ans = getAns(prices, 0, 0, n, fee, dp);
    return ans;
    }
};