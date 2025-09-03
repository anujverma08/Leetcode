class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightMax(n, 0);
        rightMax[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int leftMax = height[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            leftMax = max(height[i], leftMax);
            ans += min(leftMax, rightMax[i]) - height[i];
        }
        return ans;
    }
};