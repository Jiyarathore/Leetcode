class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        // }
        // int n=nums.size();
        // int tot=n*(n+1)/2;
        // return tot-sum;
        
        int xor1=0;
        for(int num:nums){
            xor1=xor1^num;
        }
        for(int i=0;i<=nums.size();i++){
            xor1=xor1^i;
        }
        return xor1;
    }
};