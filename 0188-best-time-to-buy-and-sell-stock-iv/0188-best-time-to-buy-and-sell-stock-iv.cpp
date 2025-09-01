class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        
        for(int ind = n- 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
                    if(buy){
                        int profit = -prices[ind] + dp[ind + 1][0][cap];
                        profit = max(profit, dp[ind + 1][1][cap]);
                        dp[ind][buy][cap] = profit;
                    }else{
                        int profit = prices[ind] + dp[ind + 1][1][cap - 1];
                        profit = max(profit, dp[ind + 1][0][cap]);
                        dp[ind][buy][cap] = profit;
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};