class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        int min = (int) n / 3 + 1;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1++;
                ele1 = nums[i];
            }else if(cnt2 == 0 && nums[i] != ele1){
                cnt2++;
                ele2 = nums[i];
            }else if(ele1 == nums[i]){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }else{
                cnt1--,cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0,cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]){
                cnt1++;
            }else if(ele2 == nums[i]){
                cnt2++;
            }
        }
        if(cnt1 >= min) ans.push_back(ele1);
        if(cnt2 >= min) ans.push_back(ele2);
        return ans;
    }
};