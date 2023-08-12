class Solution {
public:
//     Brute force
//     REcursive version Time Complexity : O(3M + N), where M is size of A and N is size of B. We have 3 choices at each recursion and max recursion depth is M+N.
// Space Complexity : O(M + N), max depth of recursive stack.
    
//     int ans=0;
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//          solve(nums1,nums2,0,0);
//         return ans;
//     }
    
//     int solve(vector<int>&A, vector<int>&B,int i, int j){
//         if(i>=size(A) || j>=size(B)) return 0;
        
//         solve(A,B,i+1,j), solve(A,B,i,j+1);;
        
//         int common=A[i]==B[j] ? 1+solve(A,B,i+1,j+1) : 0;
//         ans=max(ans,common);
//         return common;
//     }
    
//     Iterative approach Time Complexity : O(M * N * min(M,N)), Here, at each possible (i, j) we find longest common subarray. There at total of M*N pairs and we can extend at max O(min(M, N)) from each pair.
// Space Complexity : O(1)
    
//     int findLenght(vector<int>&a , vector<int>&b){
//         int m=size(a), n=size(b),ans=0;
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 int len=0;
//                 while(i+len < m && j+len<n && a[i+len]==b[j+len]) len++;
//                 ans=max(ans,len);
//             }
//         }
//         return ans;
//     }
    
//     Recursive DP - Memoization :
    
    int ans=0;
    int findLength(vector<int>&a, vector<int>&b){
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(a,b,0,0,dp);
        return ans;
    }
    int solve(vector<int>&a, vector<int>&b,int i,int j,vector<vector<int>>&dp){
        if(i>=size(a) || j>=size(b)) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        solve(a,b,i+1,j,dp), solve(a,b,i,j+1,dp);
        dp[i][j]=a[i]==b[j] ? solve(a,b,i+1,j+1,dp) +1 :0;
        ans=max(ans,dp[i][j]);
        return dp[i][j];
    }
};