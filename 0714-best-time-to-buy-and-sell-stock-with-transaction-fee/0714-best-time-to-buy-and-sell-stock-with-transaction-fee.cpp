class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = (int)prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
       
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                if(!buy)
                {
                    dp[i][buy] = max(dp[i+1][buy],-prices[i]+dp[i+1][1]);
                }
                else
                {
                    dp[i][buy] = max(dp[i+1][buy],prices[i]+dp[i+1][0]-fee);
                }
                // dp[i][buy] = max(0,dp[i][buy]);
            }
        }

        return dp[0][0];

        
    }
};