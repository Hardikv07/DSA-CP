class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        const int mod = 1e9 + 7;
        int offset = abs(sum);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));
        //   dp[0][0]=1;
        auto fun = [&](auto&& self, int idx, int s) -> int {
            if (s == target && idx == n)
                return 1;
            if (idx >= n)
                return 0;
            if (dp[idx][s + offset] != -1)
                return dp[idx][s + offset] % mod;
            int one = self(self, idx + 1, s + nums[idx]) % mod;
            int two = self(self, idx + 1, s - nums[idx]) % mod;

            return (dp[idx][offset + s] = one + two) %= mod;
        };

        return fun(fun, 0, 0) % mod;
    }
};
