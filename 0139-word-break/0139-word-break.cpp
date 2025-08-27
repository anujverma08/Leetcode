class Solution {
public:
    bool solve(int start, vector<string>& wordDict, string s){
        if(start == s.size()){
            return true;
        }

        for(auto word : wordDict){
            int len = word.size();

            if(start + len <= s.size() && s.substr(start,len) == word){
                if(solve(start + len,wordDict,s)){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0, wordDict, s);
    }
};