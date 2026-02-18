class Solution {
public:
    bool hasAlternatingBits(int n) {
        int f = n&1;
        for(int i=0; i<32; i++)
        {
            if(n < (1<<i))return true;
            if(f)
            {
                if((n&(1<<i)) == 0)return false;
            }
            else
            {
                if((n&(1<<i)))return false;
            }
            f^=1;
        }
        return true;
    }
};