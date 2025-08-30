class Solution {
public:
   long long solve(vector<int>& piles, int h){
        long long tH = 0;
        for(int i = 0; i < piles.size(); i++){
            tH += ceil((double)piles[i] / (double)h);
        }
        return tH;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;

            long long th = solve(piles,mid);
            if(th <= h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            
        }
        return low;
    }
};