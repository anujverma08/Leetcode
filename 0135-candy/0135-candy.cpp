class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = n;
        int i = 1;
        while(i < n){cx
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i < n && ratings[i] > ratings[i - 1]){ 
                peak = peak + 1;
                sum += peak;
                i++;

            }
            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                down = down + 1;
                sum += down;
                i++;
            }

           sum -= min(peak,down);
        }
        return sum;
    }
};