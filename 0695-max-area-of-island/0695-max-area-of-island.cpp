class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row,
            int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        int count = 1;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            vector<pair<int, int>> directions = {
                {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

            for (auto dir : directions) {
                int nrow = x + dir.first;
                int ncol = y + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    count++;
                }
            }
        }
        return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int area = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if(!visited[row][col] && grid[row][col] == 1){
                    int tempArea = bfs(grid, visited, row, col);
                    area = max(area, tempArea);
                }
            }
        }

        return area;
    }
};