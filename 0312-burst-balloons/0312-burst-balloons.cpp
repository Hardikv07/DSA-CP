/*

1 2 3 4 5
1 2 3
  2 3 4
    3 4 5
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = (int)nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        auto fun = [&](auto &&self, int i,int j)->int{
            if(i>j)return 0;

            int cost = 0;
            if(dp[i][j] != -1)return dp[i][j];
            for(int k=i; k<=j; k++)
            {
                int coins = nums[i-1]*nums[k]*nums[j+1];
                int rem = self(self,i,k-1) + self(self,k+1,j);
                cost = max(cost,coins+rem);
            }

            return dp[i][j] = cost;
        };

        return fun(fun,1,n);
    }
};