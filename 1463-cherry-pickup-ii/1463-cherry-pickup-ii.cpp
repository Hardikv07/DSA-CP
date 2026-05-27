class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        function<int(int, int, int)> fun =
            [&](int x, int y1, int y2) -> int {

            if (y1 < 0 || y1 >= m || y2 < 0 || y2 >= m) {
                return -1e9;
            }

            if(dp[x][y1][y2] != -1)return dp[x][y1][y2];

            if (x == n - 1) {
                if (y1 == y2) {
                    return grid[x][y1];
                } 
                return grid[x][y1] + grid[x][y2];
            }

            int ans = INT_MIN;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {

                    int tmp;

                    if (y1 == y2) {
                        tmp = grid[x][y1] +
                              fun(x + 1, y1 + i, y2 + j);
                    } else {
                        tmp = grid[x][y1] + grid[x][y2] +
                              fun(x + 1, y1 + i, y2 + j);
                    }

                    ans = max(ans, tmp);
                }
            }

            return dp[x][y1][y2] = ans;;
        };

        return fun(0, 0, m - 1);
    }
};