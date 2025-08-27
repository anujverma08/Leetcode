class Solution {
public:
    void solve(int index, vector<vector<int>>& res, vector<int>& sub,
               vector<int>& candidates, int target) {
        if (index >= candidates.size() || target < 0)
            return;
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        sub.push_back(candidates[index]);
        solve(index, res, sub, candidates, target - candidates[index]);

        sub.pop_back();
        solve(index + 1, res, sub, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        solve(0, res, sub, candidates, target);
        return res;
    }
};