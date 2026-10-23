class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int andd = -1;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=i){
            if(andd == -1)andd = nums[i];
            else andd &= nums[i];
        }
        }
        return max(0,andd);
    }
};