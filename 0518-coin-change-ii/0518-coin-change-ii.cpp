class Solution {
public:
//     memorization
    int changeUtil(vector<int>&arr, int ind, int T, vector<vector<long>>&dp){
        if(ind==0) return (T%arr[0]==0);
        
        if(dp[ind][T]!=-1) return dp[ind][T];
        
        long notTaken=changeUtil(arr,ind-1,T,dp);
        
        long taken=0;
        if(arr[ind]<=T) 
            taken=changeUtil(arr,ind,T-arr[ind],dp);
        
        return dp[ind][T]=notTaken+taken;
    }
    
    int change(int T, vector<int>& arr){
        int n=arr.size();
        vector<vector<long>>dp(n,vector<long>(T+1,-1));
        return changeUtil(arr,n-1,T,dp);
    }
};