class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        auto fun = [&](auto &&self,int i,int j)->int{
            if(i==n)return m-j;
            if(j==m)return n-i;

            if(dp[i][j]!=-1)return dp[i][j];

            if(word1[i]==word2[j])
            {
                return self(self,i+1,j+1);
            }


            int ins = 1 + self(self,i,j+1);
            int del = 1 + self(self,i+1,j);
            int rep = 1 + self(self,i+1,j+1);
            
            return dp[i][j] = min(ins,min(del,rep));
        };
        return fun(fun,0,0);
    }
};