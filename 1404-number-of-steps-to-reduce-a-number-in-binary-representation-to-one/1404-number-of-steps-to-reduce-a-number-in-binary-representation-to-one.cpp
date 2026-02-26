class Solution {
public:
    /*
    1101 -> 13
    1110 -> 14 +1
    111 -> 7  /2
    1000 -> 8 +1
    100 ->4 /2
    10 -> 2 /2
    1 -> /2


    make it to nearest power of two
    then /= 2;

    pow of two (n&(n-1)) == 0;


    if all ones ?
    make first to 1 rest to 0

    else

    if odd swap last,second last
    else remove last

    */

    int numSteps(string s) {
        int ans = 0;

        auto add1 = [&]()->void{
            int n = s.length();
            int carry = 1;
            for (int i = n - 1; i >= 0; --i) {
                int sum = (s[i] - '0') + carry;

                s[i] = (sum % 2) + '0';

                carry = sum / 2;

                if (carry == 0) {
                    break;
                }
            }

            if (carry) {
                s.insert(0, 1, '1');
            }

        };

        while (s != "1") {
            if (s.back() == '1') {
                add1();
            } else {
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};