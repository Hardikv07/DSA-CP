#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

class Solution {
public:
    int earliestFinishTime(vector<int>& land, vector<int>& ld,
                           vector<int>& water, vector<int>& wd) {

        int ans = INT_MAX;

        auto solve = [&](vector<int>& s1, vector<int>& d1,
                         vector<int>& s2, vector<int>& d2) {

            vector<int> finish;
            int mnFinish = INT_MAX;

            for (int i = 0; i < sz(s1); i++) {
                finish.push_back(s1[i] + d1[i]);
                mnFinish = min(mnFinish, s1[i] + d1[i]);
            }

            sort(all(finish));

            for (int i = 0; i < sz(s2); i++) {
                int start2 = s2[i];
                int dur2 = d2[i];

                if (mnFinish <= start2)
                    ans = min(ans, start2 + dur2);

                auto it = lower_bound(all(finish), start2);
                if (it != finish.end())
                    ans = min(ans, *it + dur2);
            }
        };

        solve(land, ld, water, wd);
        solve(water, wd, land, ld);

        return ans;
    }
};