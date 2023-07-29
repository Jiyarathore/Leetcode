class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int indexpos=0,indexneg=1;
        vector<int>v(nums.size(),0);
        for(auto num:nums){
            if(num>0){
                v[indexpos]=num;
                indexpos+=2;
            }
            else if(num<0){
                v[indexneg]=num;
                indexneg+=2;
            }
        }
        return v;
    }
};