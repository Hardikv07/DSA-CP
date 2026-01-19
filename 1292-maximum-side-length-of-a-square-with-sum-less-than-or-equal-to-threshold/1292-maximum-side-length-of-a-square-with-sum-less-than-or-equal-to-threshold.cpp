#define ll long long
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int th) {
        ll n = mat.size();
        ll m = mat[0].size();

        if (th == 0) {
            return min(n, m);
        }
        vector<vector<ll>> pre(n, vector<ll>(m));

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                pre[i][j] = mat[i][j];

                if (i > 0)
                    pre[i][j] += pre[i - 1][j];

                if (j > 0)
                    pre[i][j] += pre[i][j - 1];

                if (i > 0 && j > 0) {
                    pre[i][j] -= pre[i - 1][j - 1];
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                for (ll s = max(ans, 1LL); s <= min(n, m); s++) {
                    if (i + s - 1 < n && j + s - 1 < m) {
                        ll r = i + s - 1;
                        ll c = j + s - 1;

                        ll sum = pre[r][c];
                        if (i > 0)
                            sum -= pre[i - 1][c];
                        if (j > 0)
                            sum -= pre[r][j - 1];
                        if (i > 0 && j > 0)
                            sum += pre[i - 1][j - 1];

                        if (sum <= th)
                            ans = max(ans, s);
                    } else
                        break;
                }
            }
        }

        return ans;
    }
};