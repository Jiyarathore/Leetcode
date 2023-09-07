class Solution {
public:
    
    int findTargetSumWaysUtil(int ind, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int notTaken=findTargetSumWaysUtil(ind-1,target,nums,dp);
        
        int taken=0;
        if(nums[ind]<=target) 
            taken=findTargetSumWaysUtil(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target]=(notTaken+taken);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        
        if(totSum-target<0) return 0;
        if((totSum-target)%2==1) return 0;
        
        int s2=(totSum-target)/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return findTargetSumWaysUtil(n-1,s2,nums,dp);
    }
};