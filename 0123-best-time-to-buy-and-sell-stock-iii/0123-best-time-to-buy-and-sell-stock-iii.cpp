class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int>* p;

    int solve(int day,int buy,int cap){
        if(day >= p->size() || cap == 0) return 0;

        if(dp[day][buy][cap] != -1)
            return dp[day][buy][cap];

        if(!buy)
            return dp[day][buy][cap] =
                max(solve(day+1,0,cap),
                    -(*p)[day] + solve(day+1,1,cap));

        return dp[day][buy][cap] =
            max(solve(day+1,1,cap),
                (*p)[day] + solve(day+1,0,cap-1));
    }

    int maxProfit(vector<int>& prices) {
        p = &prices;
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(3,-1)));

        return solve(0,0,2);
    }
};