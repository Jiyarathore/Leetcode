class Solution {
public:
    
    int getAns(vector<int>&arr, int ind, int buy, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        
        int profit=0;
        
        if(buy==0){
            profit=max(0+getAns(arr, ind+1,0,n,dp), -arr[ind] + getAns(arr, ind+1,1,n,dp));
        }
        if(buy==1){
            profit=max(0+getAns(arr, ind+1,1,n,dp), arr[ind] + getAns(arr, ind+1,0,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& a) {
        // int maxProfit=0;
        // for(int i=1;i<a.size();i++){
        //     maxProfit+=max(a[i]-a[i-1],0);
        // }
        // return maxProfit;
        int n=a.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        if(n==0) return 0;
        
        int ans=getAns(a,0,0,n,dp);
        return ans;
    }
};