class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
          m[nums[i]]++;  
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        for(auto i:m){
            minHeap.push({i.second,i.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>v;
        while(minHeap.size()>0){
            v.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return v;
    }
};