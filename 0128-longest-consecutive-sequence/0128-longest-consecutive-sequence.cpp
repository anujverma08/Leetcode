class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> set;
        int longest = 1;
        for(int i : nums){
            set.insert(i);
        }
        for(auto i : set){
            if(set.find(i - 1) == set.end()){
                int x = i;
                int cnt = 1;
                while(set.find(x+1) != set.end()){
                    cnt = cnt + 1;
                    x = x + 1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;

    }
};