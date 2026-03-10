class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
           int n = matrix.size();
           int m  = matrix[0].size();
           vector<vector<int>> dp(n,vector<int>(m,0));
           for(int i=0; i<n; i++)
           {
            for(int j=0; j<m; j++)
            {
                dp[i][j] = matrix[i][j];
                int val = INT_MAX;
                if(i-1>=0 && j-1>=0)val = min(val,dp[i-1][j-1]);
                if(i-1>=0)val = min(val,dp[i-1][j]);
                if(i-1>=0 && j+1<m)val = min(val,dp[i-1][j+1]);
                if(val!=INT_MAX)
                dp[i][j] += val;
            }
           }
          return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};