class Solution {
public:
    vector<int> LPS(string& pattern){
        int n = pattern.size();
        vector<int> lps(n , 0);
        int len = 0;
        int i = 1;

        while(i < n){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = len;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps = LPS(needle);
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m){
                    return i - j;
                }
            }else{
                if(j != 0){
                    j = lps[j - 1];
                }else{
                    i++;
                }
            }
        }
        return -1;    
    }
};