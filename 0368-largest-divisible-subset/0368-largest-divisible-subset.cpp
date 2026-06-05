class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int bestLen = 1;
        int start = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 &&
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > bestLen) {
                bestLen = dp[i];
                start = i;
            }
        }

        vector<int> ans;
        int cur = start;

        while (cur != -1) {
            ans.push_back(nums[cur]);
            cur = parent[cur];
        }

        return ans;
    }
};