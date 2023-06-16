//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// By using Treaversal

// class Solution {
    
//     void dfs(int node, vector<int>adjls[], int vis[]){
//         vis[node]=1;
//         for(auto it: adjls[node]){
//             if(!vis[it]){
//                 dfs(it,adjls,vis);
//             }
//         }
//     }
//   public:
//     int numProvinces(vector<vector<int>> adj, int V) {
//         // code here
//         vector<int>adjls[V];
        
//         // to change adjancy matrix to list
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(adj[i][j]==1 && i!=j){
//                     adjls[i].push_back(j);
//                     adjls[j].push_back(i);
//                 }
//             }
//         }
//         int vis[V]={0};
//         int c=0;
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 c++;
//                 dfs(i,adjls,vis);
//             }
//         }
//         return c;
//     }
// };



// By using Disjoint set

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findPar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findPar(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
        if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        
         if(ulp_u==ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	int numProvinces(vector<vector<int>>adj,int V){
	    DisjointSet ds(V);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<V;j++){
	            if(adj[i][j]==1){
	                ds.unionBySize(i,j);
	            }
	        }
	    }
	    int c=0;
	    for(int i=0;i<V;i++){
	        if(ds.findPar(i)==i) c++;
	    }
	    return c;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends