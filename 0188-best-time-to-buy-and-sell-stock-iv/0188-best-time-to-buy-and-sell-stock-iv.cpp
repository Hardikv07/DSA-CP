class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = (int)prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1)));
        
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=k; cap++)
                {
                    if(!buy)
                    {
                        dp[i][buy][cap] = max(dp[i+1][buy][cap],-prices[i]+dp[i+1][1][cap]);
                    }
                    else
                    {
                        dp[i][buy][cap] = max(dp[i+1][buy][cap],prices[i]+dp[i+1][0][cap-1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};