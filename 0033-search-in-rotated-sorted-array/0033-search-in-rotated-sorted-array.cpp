class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
        int high=n-1,low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==target) return mid;
            
//             if left part is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else low=mid+1;
            }
            
//             right part is osrted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};