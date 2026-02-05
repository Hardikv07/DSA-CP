class Solution {
public:
   /*
   
   1 2  3 4
   3 -2 1 1
   4 
    1   2
   -10 -10
    

   */


    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
            {
                res[i] = nums[((i+n-abs(nums[i])%n)%n)];
            }
            else
            {
                res[i] = nums[(i+nums[i])%n];
            }
        }
        return res;
    }
};