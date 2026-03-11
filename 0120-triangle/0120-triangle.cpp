class Solution {
public:
    int minimumTotal(vector<vector<int>>& matrix) {
       
               int n = matrix.size();
              vector<vector<int>> dp = matrix;
              for(int i=0; i<n; i++)
              {
                for(int j=0; j<matrix[i].size(); j++)
                {
                    int val = INT_MAX;
                    if(i-1>=0 && j<dp[i-1].size())
                     val = dp[i-1][j];

                    if(i-1>=0 && j-1>=0)
                    {
                        val= min(val,dp[i-1][j-1]);
                    }
                    if(val!=INT_MAX)dp[i][j] += val;
                }
              }
              return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};