class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>indegree(V);
        vector<vector<int>>adjRev(V);
        
        for(int i=0;i<V;i++){
            for(auto node:graph[i]){
                adjRev[node].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int nod=q.front();
            q.pop();
            
            safeNodes.push_back(nod);
            for(auto it:adjRev[nod]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
    }
};