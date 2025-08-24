class Solution {
public:
    bool isValid(string& s){
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count++;
            }else{
                count--;
            }
            if(count < 0) return false;
        }
        if (count == 0) return true;
        return false;
    }
    void solve(int n,vector<string>& res, string& curr){
        if(curr.size() == 2*n){
            if(isValid(curr)){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(n,res,curr);
        curr.pop_back();

        curr.push_back(')');
        solve(n,res,curr);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        solve(n,result,curr);
        return result;
    }
};