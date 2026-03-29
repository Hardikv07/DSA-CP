class Solution {
public:
    int helper(vector<int> nums,int k)
    {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int l = 0,r = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
         mpp[nums[r]]++;
         while(mpp.size() > k)
         {
            mpp[nums[l]]--;
            if(mpp[nums[l]] <= 0)
            {
                mpp.erase(nums[l]);
            }
            l++;
         }
         ans += (r-l+1);
         r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums,k)-helper(nums,k-1);
    }
};