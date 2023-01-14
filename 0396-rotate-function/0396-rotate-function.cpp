class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,pro=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pro+=(nums[i]*i);
        }
        int ans=pro;
        int n=nums.size();
        for(int i=nums.size()-1;i>0;i--){
            pro+=(sum-(nums[i]*n));
            ans=max(ans,pro);
        }
        return ans;
    }
};