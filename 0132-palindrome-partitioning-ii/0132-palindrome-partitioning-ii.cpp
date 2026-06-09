class Solution {
public:
    int minCut(string s) {
        int n = (int)s.size();
        auto isp = [&](int i,int j)->bool{
            while(i<j)
            {
                if(s[i]!=s[j])return false;
                i++,j--;
            }
            return true;
        };
        vector<int> dp(n+1,-1);
        auto fun = [&](auto &&self,int i)->int{
            if(i>=n)return 0;
            int cost = 1e9;
            if(dp[i]!=-1)return dp[i];
            for(int k=i; k<n; k++)
            {
                if(isp(i,k))
                {
                    cost = min(cost,1 + self(self,k+1));
                }
            }
            return dp[i] = cost;
        };
        return fun(fun,0)-1;
    }
};