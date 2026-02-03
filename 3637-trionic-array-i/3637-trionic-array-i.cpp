class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; 
        int i = 0;

        if (nums[i] >= nums[i + 1]) return false;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i + 1 >= n || nums[i] <= nums[i + 1]) return false;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        if (i + 1 >= n || nums[i] >= nums[i + 1]) return false;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};
