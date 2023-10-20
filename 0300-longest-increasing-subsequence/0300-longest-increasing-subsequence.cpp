class Solution {
public:
//     memorization
//     int f(int ind, int prev_ind, vector<int>&nums, int n, vector<vector<int>>&dp){
//         if(ind==n) return 0;
//         if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        
//         int len=0+f(ind+1,prev_ind,nums,n,dp);
//         if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
//             len=max(len,1+f(ind+1,ind,nums,n,dp));
//         }
//         return dp[ind][prev_ind+1]=len;
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n, vector<int>(n+1,-1));
//         return f(0,-1,nums,n, dp);
//     }
    
//     Binary search
    
      int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
      
          vector<int>temp;
          temp.push_back(arr[0]);
          int len=1;
          for(int i=1;i<n;i++){
              if(arr[i]>temp.back()){
                  temp.push_back(arr[i]);
                  len++;
              }
              else{
                  int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                  
                  temp[ind]=arr[i];
              }
          }
          return len;
      }
    
};