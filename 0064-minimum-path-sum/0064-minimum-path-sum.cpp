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
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, grid, dp);
    }
};