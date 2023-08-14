class Solution {
public:
    
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, queue<pair<int,int>>&q, int i, int j, vector<vector<int>>&dirs){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0)
            return;
        
        visited[i][j]=true;
        q.push({i,j});
        
        for(auto& dir:dirs){
            dfs(grid,visited,q,i+dir[0],j+dir[1],dirs);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        queue<pair<int,int>>q;
        bool  found=false;
        
//         dfs from 1st island to put all cells in queue to start bfs from Island 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,visited,q,i,j,dirs);
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        
        int step=0;
        while(!q.empty()){
            int size=q.size();
            
            while(size-- > 0){
                auto curr=q.front();
                q.pop();
                
                for(auto& dir : dirs){
                    int i=curr.first + dir[0];
                    int j=curr.second + dir[1];
                    
                    if(i>=0 && j>=0 && i<m && j<n && !visited[i][j]){
                        if(grid[i][j]==1){
                            return step;
                        }
                        
                        q.push({i,j});
                        visited[i][j]=true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
//     Time complexity O(n2)-> O(n2) DFS + O(n2) MULTISOURCE BFS
//     Space O(n2)
};