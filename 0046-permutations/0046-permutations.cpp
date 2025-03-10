class Solution {
public:
    void permute(vector<int>& nums,vector<vector<int>>& ans,vector<int>& per,vector<bool>& used){
        if(per.size() == nums.size()){
            ans.push_back(per);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                per.push_back(nums[i]);
                permute(nums,ans,per,used);
                per.pop_back();
                used[i] = false;

            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> per;
        vector<bool> used(n,false);
        permute(nums,ans,per,used);
        return ans;
    }
};