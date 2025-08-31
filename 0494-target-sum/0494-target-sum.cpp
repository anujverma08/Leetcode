class Solution {
public:
    int solve(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++){
            for(int sum = 0; sum <= target; sum++){
                int npick = dp[i - 1][sum];
                int pick = 0;
                if(nums[i - 1] <= sum) pick = dp[i - 1][sum - nums[i - 1]];

                dp[i][sum] = npick + pick;
            }
        }
        return dp[n][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int& it : nums) sum += it;
        if (sum - target < 0 || (sum - target) % 2 != 0) return 0;

        int rSum = (sum - target) / 2;
        return solve(nums,rSum); 
    }
};