class Solution {
public:
    
    int array(vector<int>& nums, int goal){
        int i=0,j=0;
        int res=0,sum=0;
        if(goal<0)
            return 0;
        
        while(j<nums.size()){
            sum+=nums[j];
            
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            res+=(j-i+1);
            
            j++;
        }
        return res;
    } 
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return array(nums,goal)-array(nums,goal-1);
    }
};