//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // using dfs
//     private:
//     bool dfsCheck(int node,vector<int>adj[],int vis[],int pathvis[]){
//         vis[node]=1;
//         pathvis[node]=1;
        
//         // traverse for adjacent nodes
//         for(auto it: adj[node]){
//             // whenn node is not visited
//             if(!vis[it]){
//                 if(dfsCheck(it,adj,vis,pathvis)==true)
//                 return true;
                
//             }
//             // if node has been previously visited 
//             // but it has to be visited on same path
//             else if(pathvis[it]){
//                 return true;
//             }
//         }
//         pathvis[node]=0;
//         return false;
//     }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         // code here
//         int vis[V]={0};
//         int pathvis[V]={0};
        
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 if(dfsCheck(i,adj,vis,pathvis)==true) return true;
//             }
//         }
//         return false;
//     }

    // using bfs toposort kahn
    
    public:
    bool isCyclic(int V, vector<int>adj[]){
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            c++;
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(c==V) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends