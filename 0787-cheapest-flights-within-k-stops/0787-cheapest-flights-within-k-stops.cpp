class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, dist}} with ‘stops’ indicating 
        // the no. of nodes between src and current node.
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{src,0}});
        
        vector<int>dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops>k) continue;
            
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int adjWt=iter.second;
                
                if(cost+adjWt<dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+adjWt;
                    q.push({stops+1,{adjNode,cost+adjWt}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};