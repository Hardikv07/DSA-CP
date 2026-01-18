class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;

        auto cnt = [&](int i, int j)->void{
            for(int k = 2; k <= 50; k++)  
            {
                if(i + k - 1 < n && j + k - 1 < m)
                {
                    set<int> st;

                    for(int r = i; r < i + k; r++)
                    {
                        int sum = 0;
                        for(int c = j; c < j + k; c++)
                            sum += grid[r][c];
                        st.insert(sum);
                    }

                    for(int c = j; c < j + k; c++)
                    {
                        int sum = 0;
                        for(int r = i; r < i + k; r++)
                            sum += grid[r][c];
                        st.insert(sum);
                    }

                    int sum = 0;
                    for(int a = 0; a < k; a++)
                        sum += grid[i + a][j + a];
                    st.insert(sum);

                    sum = 0;
                    for(int a = 0; a < k; a++)
                        sum += grid[i + a][j + k - 1 - a];
                    st.insert(sum);

                    if(st.size() == 1)
                        ans = max(ans, k);
                }
                else break;
            }
        };

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cnt(i, j);

        return ans;
    }
};
