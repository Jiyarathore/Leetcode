class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int maxi=INT_MIN,sum=0;
        while(j<nums.size()){
             sum+=nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
               maxi=max(maxi,sum);
                sum-=nums[i];
                i++;
                j++;
                
            }
        }
        return ((double)maxi/k);
    }
};