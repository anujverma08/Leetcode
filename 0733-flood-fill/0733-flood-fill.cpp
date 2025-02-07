class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,
                         vector<vector<int>>& image, int newColor, int iniColor,
                         vector<pair<int, int>>& directions) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for (int i = 0; i < 4; i++) {
            int nrow = row + directions[i].first;
            int ncol = col + directions[i].second;
            if (nrow >= 0 && nrow < n &&ncol >= 0 && ncol < m && ans[nrow][ncol] != newColor && image[nrow][ncol] == iniColor) {
                dfs(nrow, ncol, ans, image, newColor, iniColor, directions);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        dfs(sr,sc,ans,image, color, iniColor, directions);
        return ans;
    }
};