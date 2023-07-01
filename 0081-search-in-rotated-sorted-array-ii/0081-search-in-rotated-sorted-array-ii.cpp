class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n=nums.size();
        int high=n-1,low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k) return true;
            
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low=low+1;
                high=high-1;
                continue;
            }
            
//             left part is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=k && k<=nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
//             right part is sorted
            else{
                if(nums[high]>=k && k>=nums[mid]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return false;
    }
};