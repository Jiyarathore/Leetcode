class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=nums[0];
        int count=1;
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==curr){
                count++;
                if(count<=2){
                    nums[j]=nums[i];
                    j++;
                }
            }
            else{
                curr=nums[i];
                count=1;
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};