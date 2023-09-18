 struct CompareHeapElements{
        bool operator()(pair<int,int>const& p1, pair<int,int> const& p2){
            if(p1.first<p2.first){
                return true;
            }
            else if(p1.first==p2.first && p1.second<p2.second){
                return true;
            }
            return false;
        }
    };

class Solution {
public:
    
    int calculateSoldierCount(vector<int>& v){
        int l=0,h=v.size()-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(v[mid]==0) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,CompareHeapElements>maxHeap;
        
        for(int i=0;i<mat.size();i++){
            maxHeap.push({calculateSoldierCount(mat[i]),i});
            
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<int>ans;
        while(maxHeap.size()){ // pushing the top k smallest elements of min_heap to "ans"
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
		
        reverse(ans.begin(), ans.end());
        return ans;
    }
};