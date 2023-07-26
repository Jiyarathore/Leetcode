class Solution {
public:
    
    int sumByD(vector<int>&nums,int div){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%div==0){
                sum+=nums[i]/div;
            }
            else sum=sum + nums[i]/div +1;
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        
        int low=1,high=*max_element(nums.begin(),nums.end());
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(sumByD(nums,mid)<=threshold){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};