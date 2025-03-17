class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map; 
        map[0] = 1;
        int cnt = 0;
        int presum = 0;
        for(int i = 0; i < n; i++){
            presum += nums[i];
            int remove = presum - k;
            cnt += map[remove];
            map[presum]++;
        }
        return cnt;
    }
};