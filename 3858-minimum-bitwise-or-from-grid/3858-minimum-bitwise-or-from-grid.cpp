class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(auto it : grid)
            for(auto j : it)
                ans = max(ans, j);

        int bits = floor(log2(ans)) + 1;
        ans = (1 << bits) - 1;

        for(int i = bits - 1; i >= 0; i--)
        {
            int temp = ans ^ (1 << i);
            bool ok = true;

            for(int k = 0; k < n; k++)
            {
                bool found = false;
                for(int j = 0; j < m; j++)
                {
                    if((grid[k][j] & temp) == grid[k][j])
                    {
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    ok = false;
                    break;
                }
            }

            if(ok) ans = temp;
        }

        return ans;
    }
};