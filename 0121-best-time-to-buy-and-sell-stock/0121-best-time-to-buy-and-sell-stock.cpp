class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxm = prices[n - 1];
        int ans = 0;
        for(int i = n - 1 - 1; i >= 0; i--){
            if(prices[i] > maxm){
                maxm = prices[i];
            }else{
                ans =max(ans,maxm - prices[i]);
            }
        }
        return ans;
    }
};