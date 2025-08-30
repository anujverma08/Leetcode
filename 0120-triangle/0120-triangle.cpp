class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();

        vector<int> front(m);
        for(int col = n - 1; col >= 0; col--){
            front[col] = triangle[n-1][col];
        }
        for(int row = n - 2; row >= 0; row--){
            vector<int> curr(row + 1);
            for(int col = row; col >= 0; col--){
               int down = triangle[row][col] + front[col];
               int diagonal = triangle[row][col] + front[col + 1];

               curr[col] = min(down,diagonal);
            }
            front = curr;
        }
        return front[0];

    }
};