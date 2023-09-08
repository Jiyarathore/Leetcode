class Solution {
public:
//     memorization
//     int changeUtil(vector<int>&arr, int ind, int T, vector<vector<long>>&dp){
//         if(ind==0) return (T%arr[0]==0);
        
//         if(dp[ind][T]!=-1) return dp[ind][T];
        
//         long notTaken=changeUtil(arr,ind-1,T,dp);
        
//         long taken=0;
//         if(arr[ind]<=T) 
//             taken=changeUtil(arr,ind,T-arr[ind],dp);
        
//         return dp[ind][T]=notTaken+taken;
//     }
    
//     int change(int T, vector<int>& arr){
//         int n=arr.size();
//         vector<vector<long>>dp(n,vector<long>(T+1,-1));
//         return changeUtil(arr,n-1,T,dp);
//     }
    
//     Tabulation
    
     int change(int T, vector<int>& arr){
         long n=arr.size();
         
          vector<vector<long>> dp(n,vector<long>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
     }
    
};