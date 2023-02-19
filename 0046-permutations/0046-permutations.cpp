class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<=1){
            return {nums};
        }
        
        vector<vector<int>>result;
        for(int i=0;i<nums.size();i++){
            vector<int> v(nums.begin(),nums.end());
            v.erase(v.begin() + i);
            auto res = permute(v);
            
            for(int j=0;j<res.size();j++){
                vector<int>_v = res[j];
                _v.insert(_v.begin(),nums[i]); // add the nums[i] which was deleted in initial stage at statrting of vector _v
                
                result.push_back(_v);
            }
        }
        return result;
    }
};