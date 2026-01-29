class Solution {
public:
/*
4 14 2
0100 
1110
0010

1 2 2 0


*/


    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        vector<int> bits(32);
        for(int i=0; i<32; i++)
        {
            for(auto it : nums)
            {
                if(it&(1<<i))bits[i]++;
            }
        }
        int n = (int)nums.size();
        for(int i=0; i<32; i++)
        {
            if(bits[i])
            {
                ans += bits[i]*abs(n-bits[i]);
            }
        }
        return ans;
    }
};