class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        auto fun = [&](int i,int j)->int{
            int cnt = count(mat[i].begin(),mat[i].end(),1);
            int cnt2 = 0;
            for(int row=0; row<n; row++)cnt2 += (mat[row][j]==1);
            return (cnt==1)&&(cnt2==1);
        };

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j])
                ans += fun(i,j);
            }
        }
        return ans;

    }
};