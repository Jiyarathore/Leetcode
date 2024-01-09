class Solution {
public:
    
    int num(int currPos, int &endPos, int k, vector<vector<int>>&dp){
        if(currPos==endPos && k==0) return 1;
        
        if(k<=0) return 0;
        
        int &ans=dp[currPos][k];
        
        if(ans!=-1) return ans;
        
        return ans=(num(currPos+1,endPos,k-1,dp)+num(currPos-1,endPos,k-1,dp))%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
         // just shifting start and end positions by same quantity
        // max value of k can be 1000 so for all startpos <1000 then (startpos-k) would be negative so shifting startPos and endPos will save us from these cases 
        startPos+=1200;
        endPos+=1200;
        
        vector<vector<int>>dp(4000, vector<int>(k+1,-1));
        return num(startPos,endPos, k, dp);
    }
};