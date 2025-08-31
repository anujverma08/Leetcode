class Solution {
public:
    bool solve(int index, vector<int>& arr, int sum, vector<vector<int>>& dp){
        if(sum == 0) return true;

        if(index == 0) return arr[0] == sum;

        if(dp[index][sum] != -1) return dp[index][sum];

        bool nPick = solve(index - 1, arr, sum, dp);
        bool pick = false;
        if(sum >= arr[index]) pick = solve(index - 1, arr, sum - arr[index], dp);

        return dp[index][sum] = pick || nPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto ele : nums){
            sum += ele;
        }
        if(sum % 2 == 0){
            vector<vector<int>> dp(n,vector<int>(sum / 2 + 1,-1));
            return solve(n - 1,nums,sum / 2, dp);
        }
        return false;
    }
};