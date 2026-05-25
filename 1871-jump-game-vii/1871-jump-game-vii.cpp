class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n = s.size();

        if (s[n - 1] == '1')
            return false;

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int farthest = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1)
                return true;

            int l = max(u + mn, farthest + 1);
            int r = min(u + mx, n - 1);

            for (int i = l; i <= r; i++) {
                if (!vis[i] && s[i] == '0') {
                    vis[i] = 1;
                    q.push(i);
                }
            }

            farthest = max(farthest, r);
        }

        return false;
    }
};