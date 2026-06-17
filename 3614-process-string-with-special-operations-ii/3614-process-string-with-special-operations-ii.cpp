#define ll long long
class Solution {
public:
    char processStr(string s, long long k) {
        ll len = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (islower(c)) {
                len++;
            } else if (c == '*') {
                if (len > 0)
                    len--;
            } else if (c == '#') {
                len *= 2;
            }
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (islower(c)) {
                if (k == len - 1)
                    return c;
                len--;
            } else if (c == '*') {
                len++;
            } else if (c == '#') {
                len /= 2;
                k %= len;
            } else if (c == '%') {
                k = len - 1 - k;
            }
        }

        return '.';
    }
};