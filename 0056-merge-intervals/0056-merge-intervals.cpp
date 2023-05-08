class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        ans.push_back({arr[0][0],arr[0][1]});
        
        int merge =0;
        for(int i=0;i<n-1;i++){
            int j=i+1;
            if(ans[i-merge][1]>= arr[j][0]){
                ans[i-merge][1]= max(arr[j][1], ans[i-merge][1]);
                merge++;
            }
            else{
                ans.push_back({arr[j][0],arr[j][1]});
            }
        }
        return ans;
    }
};