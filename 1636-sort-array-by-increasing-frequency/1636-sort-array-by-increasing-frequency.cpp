class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>>maxHeap;
        unordered_map<int,int>m;
        vector<int>v;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        for(auto i:m){
            maxHeap.push({-1*i.second,i.first});
        }
        
        while(maxHeap.size()>0){
            int freq=-1*maxHeap.top().first;
            int ele=maxHeap.top().second;
            
            for(int i=0;i<freq;i++) v.push_back(ele);
            maxHeap.pop();
        }
        return v;
    }
};