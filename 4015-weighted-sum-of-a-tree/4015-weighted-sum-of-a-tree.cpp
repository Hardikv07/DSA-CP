#define ll long long
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        ll ans = 0;
        int n = parent.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1)
                continue;
            adj[parent[i]].push_back(i);
        }
        ll height = 0;
        vector<int> vis(n);
        auto findH = [&](auto&& self, int node, ll d) -> void {
            vis[node] = 1;
            height = max(height, d);
            for (auto it : adj[node]) {
                if (!vis[it])
                    self(self, it, d + 1);
            }
        };
        findH(findH,0,1LL);

        queue<int> q;
        q.push(0);
        int d = 0;
        while (!q.empty()) {
            int sz = q.size();
            d++;

            for (int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                ans += (nums[it] * (height-d+1));
                for(auto ch : adj[it])
                {
                    q.push(ch);
                }
            }
        }
        return ans;
    }
};