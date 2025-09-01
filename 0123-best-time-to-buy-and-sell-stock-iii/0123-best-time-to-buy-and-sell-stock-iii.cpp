class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(6, 0), curr(6, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 3; j >= 0; j--) {
                if (j % 2 == 0) {
                    int profit = -prices[i] + after[j + 1];
                    profit = max(profit, after[j]);
                    curr[j] = profit;
                } else {
                    int profit = prices[i] + after[j + 1];
                    profit = max(profit, after[j]);
                    curr[j] = profit;
                }
            }
            after = curr;
        }
        return after[0];
    }
};