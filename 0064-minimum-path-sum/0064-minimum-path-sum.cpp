class Solution {
public:
   /*
    i j+1
    i+1 j
   */

    int solve(vector<vector<int>>& grid,vector<vector<int>> &dp,int n,int m)
    {
          if(n == 0 && m == 0) return grid[0][0];
           if(n < 0 || m < 0) return 1e9;
          if(dp[n][m]!=-1)return dp[n][m];
          int sum1 = grid[n][m] + solve(grid,dp,n-1,m);
          int sum2 = grid[n][m] + solve(grid,dp,n,m-1);
          dp[n][m] = min(sum1,sum2);
          return dp[n][m];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=grid[0][0];
        solve(grid,dp,n-1,m-1);
        return dp[n-1][m-1];
    }
};