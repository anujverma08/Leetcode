class Solution {
public:
    void solve(int index, vector<string>& res, string& sb, 
               const string& input, unordered_map<char, string>& map) {
        if (sb.size() == input.size()) {
            res.push_back(sb);
            return;
        }
        const string& s = map[input[index]];
        for (char c : s) {
            sb += c;
            solve(index + 1, res, sb, input, map);
            sb.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res;
        string sb;
        solve(0, res, sb, digits, map);
        return res;
    }
};
