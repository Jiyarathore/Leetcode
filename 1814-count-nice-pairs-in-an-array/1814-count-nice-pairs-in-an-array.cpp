class Solution {
public:
    
    int reverse(int n){
        int ans=0;
        while(n>0){
            ans=ans*10 +n%10;
            n/=10;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        int ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int diff=nums[i]-reverse(nums[i]);
            if(m.count(diff)==true){
                ans=(ans+m[diff])%mod;
            }
            m[diff]++;
        }
        return ans;
    }
};