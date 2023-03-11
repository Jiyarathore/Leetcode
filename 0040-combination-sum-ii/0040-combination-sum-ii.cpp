class Solution {
public:
    
    void Ps(int ind,int target,vector<int> &v,vector<vector<int>> &ans , vector<int> &arr){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            v.push_back(arr[i]);
            Ps(i+1,target-arr[i],v,ans,arr);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        Ps(0,target,v,ans,arr);
        return ans;
    }
};

 