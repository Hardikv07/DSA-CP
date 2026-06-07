class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        auto fun = [&](auto&& self, int i, int j) -> int {
            if (j == m)
                return 1;
            if (i == n)
                return 0;

            if (dp[i][j] != -1)
                return dp[i][j];

            int ans = self(self, i + 1, j); // skip

            if (s[i] == t[j])
                ans += self(self, i + 1, j + 1); // take

            return dp[i][j] = ans;
        };

        return fun(fun, 0, 0);
    }
};