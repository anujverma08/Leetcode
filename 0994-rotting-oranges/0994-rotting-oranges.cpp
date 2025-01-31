class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        int time = 0;

        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2 ){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }

                if(grid[i][j] == 1) cntFresh++;
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int cnt = 0;
        while(!q.empty()){
            pair<pair<int,int>,int> temp = q.front();
            int x = temp.first.first;
            int y = temp.first.second;
            int t = temp.second;
            time = max(time,t);
            q.pop();

            for(auto dir : directions){
                int nrow = x + dir.first;
                int ncol = y + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 1;
                    cnt++;
                    q.push({{nrow,ncol},time+1});
                }
            }
            
        }
        if (cnt != cntFresh) return -1;
        return time;
        
        
    }
};