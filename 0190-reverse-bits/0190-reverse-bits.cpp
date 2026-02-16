class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits(32);
        for(int i=0; i<32; i++)
        {
            if(n & (1<<i))
            {
                bits[i]++;
            }
        }
        reverse(bits.begin(),bits.end());
        int ans = 0;
        for(int i=0; i<32; i++)
        {
            ans += bits[i]?(1<<i):0;
        }
        return ans;
    }
};