class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1);
        for (int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i-1] + 1;
            }
        }
        int sum = max(left[n-1],1);
        int right = 1;
        for (int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                right++;
            }else{
                right = 1;
            }
            right = max(left[i],right); 
            sum += right;
        }
        return sum;
        
    }
};