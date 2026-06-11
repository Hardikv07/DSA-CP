/*
find mx depth
count number of way to assign odd sum to it
**/

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n + 1];
        const int mod = 1e9+7;
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int depth = 0;
        int cnt = 0;
        vector<int> vis(n+1);
        auto dfs = [&](auto&& self, int node, int d) -> void {
            depth = max(depth, d);
             vis[node]=1;
            for (auto child : adj[node]) {
                if(!vis[child])
                self(self, child, d + 1);
            }
        };

        dfs(dfs, 1, 0);
        cout <<  depth;
        vector<int> dp(depth+1,-1);
       
        auto fun = [&](auto &&self,int idx,int sum)
        {
            if(idx==depth)return sum%2;
            if(dp[idx]!=-1)return dp[idx];
            int one = self(self,idx+1,sum+1)%mod;
            int two = self(self,idx+1,sum+2)%mod;
            return dp[idx] = (one+two)%mod;
        };
        return fun(fun,0,0)%mod;
    }
};