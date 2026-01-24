class Solution {
public:
  /*
  
  2 3 4 4 5 6
  2 6
  3 5
  4 4
  
  
  
  */


    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = (int)nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            ans = max(ans,nums[i]+nums[j]);
            i++,j--;
        }
        return ans;
    }

};