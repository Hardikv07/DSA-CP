class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        auto fun = [&](int num)->int{
            int sum = 0;
            while(num>0)
            {
                sum += (num%10);
                num /= 10;
            }
            return sum;
        };

        for(auto it : nums)
        {
            ans = min(ans,fun(it));
        }
        return ans;
    }
};