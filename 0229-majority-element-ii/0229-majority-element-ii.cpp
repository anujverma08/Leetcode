class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        vector<int> ans;
        int min = (int) n/3 + 1;
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
            if(map[nums[i]] == min){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};