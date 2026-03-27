class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> tmp = mat;
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        for(int i=0; i<n; i++)
        {
            if(i&1^1)
            {
                rotate(tmp[i].begin(),tmp[i].begin()+k,tmp[i].end());
            }
            else
            {
                rotate(tmp[i].rbegin(),tmp[i].rbegin()+k,tmp[i].rend());
            }
        }
        // for(auto it : mat)
        // {
        //     for(auto i : it)cout << i << " ";
        //     cout << "\n";
        // }
        return mat==tmp;
    }
};