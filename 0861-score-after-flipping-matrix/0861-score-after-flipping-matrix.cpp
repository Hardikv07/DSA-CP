#define ll long long
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++)
                    grid[i][j] ^= 1;
            }
        }

        for(int j = 1; j < m; j++) {
            int zeroCnt = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0) zeroCnt++;
            }

            if(zeroCnt > n / 2) {
                for(int i = 0; i < n; i++)
                    grid[i][j] ^= 1;
            }
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    ans += (1LL << (m - j - 1));
                }
            }
        }

        return ans;
    }
};
