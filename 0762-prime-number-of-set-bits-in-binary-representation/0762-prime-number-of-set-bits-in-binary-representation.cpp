class Solution {
public:


    int countPrimeSetBits(int left, int right) {
        auto check = [&](int num)->bool{
            if(num==1)return false;
            for(int i=2; i*i<=num; i++)
            {
                if(num%i==0)return false;
            }
            return true;
        };

        int ans = 0;
        for(int i=left; i<=right; i++)
        {
            if(check(__builtin_popcount(i)))ans++;
        }
        return ans;
    }
};