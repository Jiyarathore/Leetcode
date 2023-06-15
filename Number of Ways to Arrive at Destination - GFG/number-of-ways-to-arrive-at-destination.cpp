//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
       using ll = long long;
        vector<pair<ll,ll>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        //{dist,node}
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> ,
                        greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll edgeWeight = it.second;

                
                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dis+edgeWeight , adjNode});
                    ways[adjNode] = ways[node];

                }
                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if(dis + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends