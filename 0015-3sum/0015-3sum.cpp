class Solution {
public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int target = 0;
//         set<vector<int>>s;
//         vector<vector<int>>output;
//         for(int i=0;i<nums.size();i++){
//             int j=i+1;
//             int k=nums.size()-1;
//             while(j<k){
// int sum= nums[i]+nums[j]+nums[k];
                
//                 if(sum==target){
//                      s.insert({nums[i], nums[j], nums[k]});
//                     j++;
//                     k--;
//                     }
//                 else if(sum<target){
//                     j++;
//                 }
//                 else{
//                     k--;
//                 }
//             }
//         }
        
//         for(auto triplets : s)
//             output.push_back(triplets);
//         return output;
//     }
    
//     2 pointer approach
    
//     vector<vector<int>>threeSum(vector<int>&num){
//         sort(num.begin(),num.end());
        
//         vector<vector<int>>res;
        
// //         moves for a
//         for(int i=0;i<num.size()-2;i++){
//             if(i==0 || (i>0 && num[i]!=num[i-1])){
//                 int lo=i+1,hi=num.size()-1,sum=0-num[i];
                
//                 while(lo<hi){
//                     if(num[lo] + num[hi]==sum){
//                         vector<int>temp;
//                         temp.push_back(num[i]);
//                         temp.push_back(num[lo]);
//                         temp.push_back(num[hi]);
//                         res.push_back(temp);
                        
//                         while(lo<hi && num[lo]==num[lo+1]) lo++;
//                         while(lo<hi && num[hi]==num[hi-1]) hi--;
                        
//                         lo++;hi--;
//                     }
//                     else if(num[lo]+ num[hi]<sum) lo++;
//                     else hi--;
//                 }
//             }
//         }
//         return res;
//     }
    
//     Simple approch https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
    
     vector<vector<int>>threeSum(vector<int>&arr){
         int n=arr.size();
         vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
     }
    
};