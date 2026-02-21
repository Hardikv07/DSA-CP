#define ll unsigned int
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ll> dp(target + 1, 0);   
        dp[0] = 1;

        sort(nums.begin(), nums.end());   

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < (int)nums.size(); j++) {
                if (nums[j] > i) break;   
                dp[i] += dp[i - nums[j]];
            }
        }
        return (int)dp[target];
    }
};