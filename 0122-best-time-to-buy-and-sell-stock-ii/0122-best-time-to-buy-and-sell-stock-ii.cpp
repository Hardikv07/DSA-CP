class Solution {
public:
    /*

    7 1 5 3 6 4
    7 1 2 5 6 4

    1 inc... sell





    */

    int maxProfit(vector<int>& v) {
        int n = (int)v.size();
        int mn = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mn = min(mn, v[i]);
            int tmp = 0;
            if (i + 1 < n && mn <= v[i + 1]) {
                while (i + 1 < n && v[i] <= v[i + 1]) {

                    tmp = max(tmp, abs(mn - v[i+1]));
                    i++;
                }
            }
            else continue;
            cout << mn << " ";
            mn = INT_MAX;
            ans += tmp;
        }
        return ans;
    }
};