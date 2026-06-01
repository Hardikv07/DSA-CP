class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        int t = sum/2;

        vector<vector<int>> dp(n+1, vector<int>(sum + 1,0));
         dp[0][0]=1;
        for(int i=0; i<=t; i++)
        {
            for(int j=1; j<=n; j++)
            {
                 dp[j][i] = dp[j-1][i];

                 if(i - nums[j-1] >= 0)
                 {
                    dp[j][i] |= dp[j-1][i-nums[j-1]];
                 }
            }
        }
        
        auto fun = [&](auto &&self, int idx,int sm)->bool{
             if(sm==t)return true;
             if(idx>=n || sm>t)return false;

             if(dp[idx][sm]!=-1)return dp[idx][sm];

             int one = self(self,idx+1,sm);
             int two = self(self,idx+1,sm+nums[idx]);
             return dp[idx][sm] = one | two;
        };

        return dp[n][t];

    }
};