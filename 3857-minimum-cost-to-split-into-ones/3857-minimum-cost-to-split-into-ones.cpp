class Solution {
public:

    int solve(vector<int> &dp, int n)
    {
        if(n==1)return 0;
        if(dp[n]!=-1)return dp[n];

       int first = n/2;
       int second = n-first;
        return dp[n] = first*second + solve(dp,first) + solve(dp,second);
    }

    int minCost(int n) {
        vector<int> dp(n+1,-1);
        return solve(dp,n);
    }
};