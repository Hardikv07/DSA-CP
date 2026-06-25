#define ll long long
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        ll ans = 0;
         int n = nums.size();
         vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        auto fun = [&](auto &&self,int idx,int skip)->ll{
            if(idx>=n)return 0;
            if(dp[idx][skip]!=-1)return dp[idx][skip];
            ll cost = 0;
            if(idx>0 && idx+1<n)
            {
                cost = max(0LL,0LL+max(nums[idx-1],nums[idx+1])+1 - nums[idx]);
            }
             ll ans = 1e18;
                ans = cost + self(self,idx+2,skip);
            if(skip)
            {
                ans = min(ans,0LL+self(self,idx+1,0));
            }
            
            return dp[idx][skip]=ans;
        };
        if(n&1)
        return fun(fun,1,0);
        else return fun(fun,1,1);
    }
};