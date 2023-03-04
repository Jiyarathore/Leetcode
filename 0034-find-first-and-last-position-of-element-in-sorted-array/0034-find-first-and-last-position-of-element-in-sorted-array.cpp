class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size(),l=0,r=n-1; 
        vector<int>v(2,-1);
        //for initial index
        while(l<=r){
            int m=(r+l)/2;
            if (nums[m]<target) l=m+1;
            else if(nums[m]>target) r=m-1;
            else {
            if(m==0 || nums[m]!=nums[m-1]) {v[0]=m; break;}
            else r=m-1;
            }
        }
        // for ending index
        l=0;r=n-1;
        while(l<=r){
            int m=(r+l)/2;
            if (nums[m]<target) l=m+1;
            else if(nums[m]>target) r=m-1;
            else {
            if(m==n-1 || nums[m]!=nums[m+1]) {v[1]=m; break;}
            else l=m+1;
            }
        }
        return v;
    }
};