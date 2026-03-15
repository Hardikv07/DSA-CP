#define ll long long
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& v) {
        int n = v.size();
        ll low = 1, high = 1e18;

        auto check = [&](ll thr) -> bool {
            ll total = mountainHeight;

            for (int i = 0; i < n; i++) {
                ll work = thr/v[i];
                ll r = (sqrt(1 + 8.0 * work) - 1) / 2;
                total -= r;
                if (total <= 0)
                    return true;
            }
            return total <= 0;
        };

        while (low <= high) {
            ll mid = (low + high) >> 1;

            if (check(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};