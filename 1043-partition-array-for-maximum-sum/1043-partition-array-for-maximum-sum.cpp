class Solution {
public:
    int solve(int ind, int k, vector<int>& arr, vector<int>& dp, int& n){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxEle = INT_MIN;
        int maxi = INT_MIN;
        for(int j = ind; j < min(n , ind + k); j++){
            len++;
            maxEle = max(maxEle, arr[j]);
            int sum = maxEle * len + solve(j + 1, k, arr, dp, n);
            maxi = max(maxi, sum);
        }
        return dp[ind] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp, n);
    }
};