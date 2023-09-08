//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

// Memorization
    // int knapSackUtil(int* wt, int* val, int ind, int W, vector<vector<int>>&dp){
    //     if(ind==0){
    //         return (W/wt[0])*val[0];
    //     }
        
    //     if(dp[ind][W]!=-1) return dp[ind][W];
        
    //     int nonTaken= 0+knapSackUtil(wt,val,ind-1,W,dp);
        
    //     int taken=INT_MIN;
    //     if(wt[ind]<=W)
    //     taken=val[ind] + knapSackUtil(wt,val,ind,W-wt[ind],dp);
        
    //     return dp[ind][W]=max(nonTaken, taken);
    // }
    
    // int knapSack(int n, int W, int val[], int wt[])
    // {
    //     // code here
        
    //     vector<vector<int>>dp(n,vector<int>(W+1,-1));
    //     return knapSackUtil(wt,val,n-1,W,dp);
    // }
    
    // Tabulation
    
    int knapSack(int n, int W, int val[], int wt[]){
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        for(int i=wt[0];i<=W;i++){
            dp[0][i]=(i/wt[0])*val[0];
        }
        
        for(int ind=1;ind<n;ind++){
            for(int cap=0;cap<=W;cap++){
                int nonTaken=0+dp[ind-1][cap];
                
                int taken=INT_MIN;
                if(wt[ind]<=cap){
                    taken=val[ind]+dp[ind][cap-wt[ind]];
                }
                
                dp[ind][cap]=max(nonTaken,taken);
            }
        }
        return dp[n-1][W];
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