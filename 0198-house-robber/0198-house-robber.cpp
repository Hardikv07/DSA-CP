class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=nums[0];
        if(n>1)
        dp[1]=max(nums[1],nums[0]);
        for(int i=2; i<n; i++)
        {
           dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};