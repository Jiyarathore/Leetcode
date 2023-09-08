//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   memorization

//   int cutRodUtil(int* price, int ind, int n, vector<vector<int>>dp){
//       if(ind==0) return n*price[0];
      
//       if(dp[ind][n]!=-1) return dp[ind][n];
      
//       int notTaken=0+cutRodUtil(price,ind-1,n,dp);
      
//       int taken=INT_MIN;
//       int rodLenght=ind+1;
//       if(rodLenght<=n)
//       taken=price[ind] + cutRodUtil(price,ind,n-rodLenght,dp);
      
//       return dp[ind][n]=max(taken,notTaken);
      
//   }
  
//     int cutRod(int price[], int n) {
//         //code here
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
//         return cutRodUtil(price, n-1,n,dp);
//     }

// Tbulation

    int cutRod(int price[], int n){
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++){
            dp[0][i]=i*price[0];
        }
        
        for(int ind=1;ind<n;ind++){
            for(int length=0;length<=n;length++){
                int notTaken=0+dp[ind-1][length];
                
                int taken=INT_MIN;
                int rodLength=ind+1;
                if(rodLength<=length)
                taken=price[ind]+dp[ind][length-rodLength];
                
                dp[ind][length]=max(notTaken,taken);
                
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends