class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        auto dfs = [&](auto &&self, int i, int j) -> int {
            if (i == n || j == m) return 0;

            if (dp[i][j] != -1) return dp[i][j];

            if (s1[i] == s2[j])
                return dp[i][j] = 1 + self(self, i + 1, j + 1);

            return dp[i][j] =
                max(self(self, i + 1, j),
                    self(self, i, j + 1));
        };

        return dfs(dfs, 0, 0);
    }
};