#define all(x) x.begin(), x.end()
class Solution {
public:
    bool canCross(vector<int>& v) {

        int n = v.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        auto fun = [&](auto&& self, int prev, int idx) -> int {
            if (idx == n - 1)
                return 1;
            if (idx >= n || prev<0)
                return 0;

            if(dp[idx][prev]!=-1)return dp[idx][prev];
             
            auto one = v.end();
            if(prev-1>0)
            one = lower_bound(all(v), prev - 1 + v[idx]);
            int ans = 0;

            if (one != v.end() && *one == prev - 1 + v[idx]) {
                ans |= self(self, prev - 1, one - v.begin());
            }
            auto two = v.end();
            if(prev>0)
            two = lower_bound(all(v), prev+v[idx]);
            if (two != v.end() && *two == prev+v[idx]) {
                ans |= self(self, prev, two - v.begin());
            }
            auto three = lower_bound(all(v), prev + 1 + v[idx]);
            if (three != v.end() && *three == prev + 1+v[idx]) {
                ans |= self(self, prev + 1, three - v.begin());
            }
            return dp[idx][prev]=ans;
        };

        return fun(fun, 0, 0);
    }
};