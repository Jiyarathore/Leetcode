class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int maxi=INT_MIN,ans=0;
        for(auto i:m){
            if(i.second>maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};