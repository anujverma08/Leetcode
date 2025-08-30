class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = m - 1; col >= 0; col--) {
                int down = dp[row + 1][col];
                int diaLeft = (col - 1 >= 0) ? dp[row + 1][col - 1] : INT_MAX;
                int diaRight = (col + 1 < m) ? dp[row + 1][col + 1] : INT_MAX;

                dp[row][col] = matrix[row][col] + min(down, min(diaLeft, diaRight));
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < m; i++){
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }
};