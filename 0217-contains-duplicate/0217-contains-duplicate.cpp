class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        bool f=false;
        for(auto i:m){
            if(i.second>1){
                f=true;
                break;
            }
        }
        return f;
    }
};