#define ll long long
class Solution {
public:
const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        ll p2 = 1;
        ll ans = 0;
        auto get = [&](int i)->void{
            while(i>0)
            {
                // cout << i%2; 
                if(i%2)
                {
                 ans = (ans + p2)%mod;
                }
                p2 = ((p2*2))%mod;
                i >>= 1;
            }
        };
        for(int i=n; i>=1; i--)
        {
            get(i);
        }
        return (int)ans;
    }
};