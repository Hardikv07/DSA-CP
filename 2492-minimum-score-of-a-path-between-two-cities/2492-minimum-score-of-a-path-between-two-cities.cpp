class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
         vector<pair<int,int>> adj[n+1];
         for(auto it : roads)
         {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
         } 

         int vis[n+1];
         memset(vis,0,sizeof(vis));
         int ans = 1e9;
         queue<int> q;
         q.push(1);
         vis[1]=1;
         while(!q.empty())
         {
            int node = q.front();
            q.pop();

            for(auto [v,w] : adj[node])
            {
                ans = min(ans,w);
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
         }
         return ans;       
    }
};