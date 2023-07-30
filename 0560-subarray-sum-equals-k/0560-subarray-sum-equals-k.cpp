class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>m;
        m[0]=1;
        int prefixSum=0,c=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remove=prefixSum-k;
            c+=m[remove];
            m[prefixSum]+=1;
        }
        return c;
    }
};