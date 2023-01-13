class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //sliding window
        int ind1=-1,ind2=-1;
        int n=nums.size();
        vector<int>num1;
        for(int x:nums){
            num1.push_back(x);
        }
        sort(num1.begin(),num1.end());
        
        for(int i=0;i<n;i++){
            if(nums[i]!=num1[i]){
                ind1=i;
                break;
            }
            
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]!=num1[j]){
                ind2=j;
                break;
            }
        }
        if(ind1==-1 or ind1==-1) return 0;
        else{
            return ind2-ind1+1;
        }
    }
};