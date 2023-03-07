class Solution {
public:
    
   void solve(vector<int>nums, vector<vector<int>>&ans,int index){
       
       if(index>=nums.size()){
           ans.push_back(nums);
           return;
       }
       unordered_set<int>s;
       for(int i=index;i<nums.size();i++){
           
           if(s.find(nums[i])!=s.end())
               continue;
           s.insert(nums[i]);
           
           swap(nums[index], nums[i]);
           solve(nums, ans, index+1);   
           swap(nums[index], nums[i]);
       }
   }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};