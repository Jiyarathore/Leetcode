class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int maxi=nums.size()/3;
        vector<int>ans;
        for(auto i:m){
            if(i.second>maxi){
                
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
// int countMajority = nums.size()/3;
//         unordered_map<int, int> map;
//         vector<int> output;
//         for(auto num : nums){
//             map[num]++;
//         }
//         for(auto num : map){
//             if(num.second > countMajority){
//                 output.push_back(num.first);
//             }
//         }
//         return output;