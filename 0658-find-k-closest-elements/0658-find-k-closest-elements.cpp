class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>minHeap;
        vector<int>v;
        for(int i=0;i<arr.size();i++){
            minHeap.push({abs(arr[i]-x),arr[i]});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(minHeap.size()>0){
            v.push_back(minHeap.top().second);
            minHeap.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};