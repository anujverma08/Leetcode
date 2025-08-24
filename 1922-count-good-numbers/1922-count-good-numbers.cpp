using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
public:
    ll findPower(ll a, ll b){
        if(b == 0) return 1;
        
        ll half = findPower(a, b / 2);
        ll res = half * half % MOD;
        if(b % 2 != 0){
            res = res * a % MOD;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll half1 = findPower(5, (n + 1)/2);
        ll half2 = findPower(4 , n/2);

        ll res = (half1 * half2)% MOD;
        return (int) res;
    }
};