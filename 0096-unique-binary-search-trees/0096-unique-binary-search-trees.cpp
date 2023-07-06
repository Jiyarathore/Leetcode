class Solution {
public:
    
  
    
    // int numTrees(int n) {
//         recusrion
//         if(n<=1) return 1;
//         int ans=0;
        
//         for(int i=1;i<=n;i++){
//             ans+=numTrees(i-1)*numTrees(n-i);
//         }
//         return ans;
        

    // }
    
//     memorixation
    
//     int numTree(int n, vector<int> &dp) {
// 	// base case
// 	if (n <= 1) return 1;
	
// 	if (! dp[n])
		
// 		for (int i = 1; i <= n; i++)
// 			dp[n] += numTree(i - 1, dp) * numTree(n - i, dp);
	
// 	return dp[n];
// }

// int numTrees(int n) {
	
// 	vector<int> dp(20);
// 	return numTree(n, dp);
// }
    
//     Tbu;ation
    
    int numTrees(int n){
        vector<int>dp(n+1);
        
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
    
    
};