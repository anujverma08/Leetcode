class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row < 0 || col < 0) return INT_MAX;

        if(dp[row][col] != -1) return dp[row][col];

        if(row == 0 && col == 0) return dp[0][0] = grid[0][0];

        int up = solve(row - 1, col, grid, dp);
        int left = solve(row, col - 1, grid, dp);
        
        int result = INT_MAX;
        if(up != INT_MAX) result = min(result, grid[row][col] + up);
        if(left != INT_MAX) result = min(result,grid[row][col] + left);

        return dp[row][col] = result;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(row == 0 && col == 0) dp[row][col] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;

                    if(row > 0) up = grid[row][col] + dp[row - 1][col];
                    if(col > 0) left = grid[row][col] + dp[row][col - 1];

                    dp[row][col] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};