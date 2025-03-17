class Solution {
public:
    vector<int> getRows(int row) {
        vector<int> result;
        result.push_back(1);
        int ele = 1;
        for (int col = 1; col < row; col++) {
            ele *= (row - col);
            ele /= col;
            result.push_back(ele);
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(getRows(i));
        }
        return ans;
    }
};