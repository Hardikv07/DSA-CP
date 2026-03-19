class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dpX(m , vector<int>(n , 0));
        vector<vector<int>> dpY(m , vector<int>(n , 0));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dpX[i][j] = (grid[i][j] == 'X');
                dpY[i][j] = (grid[i][j] == 'Y');

                if (i - 1 >= 0){
                    dpX[i][j] += dpX[i - 1][j];
                    dpY[i][j] += dpY[i - 1][j];
                }

                if (j - 1 >= 0) {
                    dpX[i][j] += dpX[i][j - 1];
                    dpY[i][j] += dpY[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    dpX[i][j] -= dpX[i - 1][j - 1];
                    dpY[i][j] -= dpY[i - 1][j - 1];
                }

                if (dpX[i][j] == dpY[i][j] && dpX[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }
};