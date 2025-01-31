class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,int i,int j){
        visited[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            pair<int,int> temp = q.front();
            int row = temp.first;
            int col = temp.second;
            q.pop();

            for(auto dir : directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});    
                }
            }
        }

        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(grid,visited,i,j);
                    
                }
            }
        }
        return count;
    }
};