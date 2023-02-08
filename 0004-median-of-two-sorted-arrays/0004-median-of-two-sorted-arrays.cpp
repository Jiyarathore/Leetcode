class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        
        sort(v.begin(),v.end());
        int n=v.size();
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};