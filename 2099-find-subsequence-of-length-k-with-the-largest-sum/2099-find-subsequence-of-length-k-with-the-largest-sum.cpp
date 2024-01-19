class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({i, nums[i]});
        }
        
        sort(v.begin(),v.end() ,[&](auto x1, auto x2){
             return x1.second > x2.second;
        });
        
        sort(v.begin(),v.begin()+k);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};