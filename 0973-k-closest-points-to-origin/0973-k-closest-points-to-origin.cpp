class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxHeap;
        vector<vector<int>>v;
        for(int i=0;i<points.size();i++){
            maxHeap.push({(points[i][0]*points[i][0]) + (points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
        while(maxHeap.size()>0){
            pair<int,int> p = maxHeap.top().second; 
        v.push_back({p.first,p.second});
            maxHeap.pop();
        }
        return v;
    }
};