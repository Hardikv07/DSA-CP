/*

node,sum,mn

*/
#define ll long long
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<pair<int, int>> adj[n];
        int low=1e9,high=0;
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (!online[v] || !online[u])
                continue;
            adj[u].push_back({v, w});
            low = min(low,w);
            high = max(high,w);
        }

        auto check = [&](int mid)->bool{
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

            pq.push({0,0});

           vector<ll> dis(n,1e18);
            dis[0]=0;

            while(!pq.empty())
            {
                auto [sum,x] = pq.top();
                pq.pop();
                if(sum>dis[x])continue;
                if(sum>k)return false;
                if(x==n-1)return true;

                for(auto [v,w] : adj[x])
                {
                    if(w<mid)continue;
                    if(dis[v] > sum+w){
                    pq.push({sum+w,v});
                    dis[v] = sum+w;
                    }
                }
            }

            return false;

        };

        if(!check(low))return -1;

        while(low <= high)
        {
            int mid = (low+high)>>1;
            if(check(mid))
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return high;

    }
};