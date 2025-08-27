class Solution {
public:
    void solve(int index,vector<vector<int>>& res, vector<int>& sub,vector<int>& nums){
        res.push_back(sub);
        for(int i = index; i < nums.size(); i++){
            if(i !+ index && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            solve(i+1,res,sub,nums);        
            sub.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        solve(0,res,sub,nums);
        return res;
    }
};