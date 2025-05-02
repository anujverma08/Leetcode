class Solution {
public:
    void generate(vector<string>& res, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        
        if (open < n)
            generate(res, current + "(", open + 1, close, n);
        
        if (close < open)
            generate(res, current + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
};