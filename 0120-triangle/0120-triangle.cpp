class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();

        vector<vector<int>> dp(n, vector<int>(m));
        for(int col = n - 1; col >= 0; col--){
            dp[n-1][col] = triangle[n-1][col];
        }
        for(int row = n - 2; row >= 0; row--){
            for(int col = row; col >= 0; col--){
               int down = triangle[row][col] + dp[row + 1][col];
               int diagonal = triangle[row][col] + dp[row + 1][col + 1];

               dp[row][col] = min(down,diagonal);
            }
        }
        return dp[0][0];

    }
};