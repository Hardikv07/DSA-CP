class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        auto fun = [&](auto&& self, int buy, int day) -> int {
            if (day >= n)
                return 0;

            if (dp[day][buy] != -1)
                return dp[day][buy];
            int profit = 0;
            if (!buy) {
                profit = max(self(self, 0, day + 1),
                             (-prices[day])+self(self, 1, day + 1));
            } else {
                profit = max(self(self, 1, day + 1),
                             prices[day] - fee + self(self, 0, day + 1));
            }
            return dp[day][buy] = max(0, profit);
        };
        return fun(fun,0,0);
    }
};