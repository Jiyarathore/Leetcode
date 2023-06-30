class Solution {
public:
//     iterative sol
//     int search(vector<int>& nums, int target) {
//         int low=0,high=nums.size()-1;
      
        
//         while(low<=high){
            
//           int mid=low+(high-low)/2;
//         if(nums[mid]==target) return mid;
//         else if(nums[mid]<target) low=mid+1;
//         else high=mid-1;
//         }
//         return -1;
//     }
    
//     Recursive sol
    
    int binary(vector<int>& nums,int low,int high, int target){
        
        if (low > high) return -1;
        
          int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) 
            return binary(nums,mid+1,high,target);
        else 
            return binary(nums,low,mid-1,target);
        
    }
    
    int search(vector<int>& nums, int target) {
         return binary(nums,0,nums.size()-1,target);
    }
};