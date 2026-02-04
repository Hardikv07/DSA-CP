class Solution {
public:

   

    int solve(int n,int &ans,vector<int> &dp)
    {
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];

        dp[n] = solve(n-1,ans,dp)+solve(n-2,ans,dp);
        return dp[n];
    }

    int climbStairs(int n) {
        int ans = 0;
        vector<int> dp(48,-1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        solve(n,ans,dp);
        return dp[n];
    }
};