//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSackUtil(int* wt, int* val, int ind, int W, vector<vector<int>>&dp){
        if(ind==0){
            return (W/wt[0])*val[0];
        }
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int nonTaken= 0+knapSackUtil(wt,val,ind-1,W,dp);
        
        int taken=INT_MIN;
        if(wt[ind]<=W)
        taken=val[ind] + knapSackUtil(wt,val,ind,W-wt[ind],dp);
        
        return dp[ind][W]=max(nonTaken, taken);
    }
    
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return knapSackUtil(wt,val,n-1,W,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends