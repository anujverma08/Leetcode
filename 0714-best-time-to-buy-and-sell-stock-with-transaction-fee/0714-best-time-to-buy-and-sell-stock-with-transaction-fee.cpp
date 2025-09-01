class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        for(int index = n - 1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy){
                    int profit = -prices[index] + dp[index + 1][0];
                    profit = max(profit, dp[index + 1][1]);
                    dp[index][buy] = profit;
                }else{
                    int profit = prices[index] - fee +dp[index + 1][1];
                    profit = max(profit, dp[index + 1][0]);
                    dp[index][buy] = profit;
                }
            }
        }
        return dp[0][1];
    }
};