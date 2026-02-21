#define vi vector<int>
class Solution {
public:

    vi dp;

int fun(vi &v, int sum)
{
    if (sum == 0) return 0;
    if (sum < 0) return INT_MAX;

    if (dp[sum] != -1) return dp[sum];

    int res = INT_MAX;

    for (int i = 0; i < (int)(v.size()); i++)
    {
        int sub = fun(v, sum - v[i]);
        if (sub != INT_MAX)
            res = min(res, 1 + sub);
    }

    return dp[sum] = res;
}

    int coinChange(vector<int>& v, int x) {
         dp.assign(x + 1, -1);

       int ans = fun(v, x);

    if (ans == INT_MAX) return -1;
    else return ans;
    }
};