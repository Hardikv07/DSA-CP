class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> mpp;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
           mpp[nums[i]]++;
           while(l<n && !mpp.empty() &&(mpp.rbegin()->first)-(mpp.begin()->first) > limit)
           {
              mpp[nums[l]]--;
              if(mpp[nums[l]]==0)mpp.erase(nums[l]);
              l++;
           }
           ans = max(ans,i-l+1);
        }
        return ans;
    }
};