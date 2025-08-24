class Solution {
public:
    void solve(int n, vector<string>& res,string curr,int open, int close){
        if(curr.size() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open < n){
            solve(n,res,curr + '(',open + 1, close);
        }
        if(close < open){
            solve(n, res, curr + ')', open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n,res,"",0,0);
        return res;
    }
};