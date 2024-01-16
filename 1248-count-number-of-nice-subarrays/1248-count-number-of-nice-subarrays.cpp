class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j=0,odd=0,c=0,total=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                odd++;
                
                if(odd>=k){
                    c=1;
                    
                    while(nums[j++]%2==0) c++;
                    total+=c;
                }
            }
            
            else if(odd>=k) total+=c;
        }
        return total;
    }
};
// https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/508217/C%2B%2B%3A-Visual-explanation.-O(1)-space.-Two-pointers