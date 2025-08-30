class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix,int n,vector<vector<int>>& dp){
        if(col < 0 || col >= n ) return 1e9;
        
        if(row == n - 1) return matrix[row][col];

        if(dp[row][col] != -1) return dp[row][col];
        int down = matrix[row][col] + solve(row + 1, col, matrix, n,dp);
        int diaLeft = matrix[row][col] + solve(row + 1, col - 1, matrix, n,dp);
        int diaRight = matrix[row][col] + solve(row + 1, col + 1, matrix, n,dp);

        int ans = min(down,min(diaLeft,diaRight));

        return dp[row][col] = ans;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini = INT_MAX;
        for(int i= 0; i < m; i++){
            mini = min(mini, solve(0,i,matrix,n,dp));
        }
        return mini;
    }
};