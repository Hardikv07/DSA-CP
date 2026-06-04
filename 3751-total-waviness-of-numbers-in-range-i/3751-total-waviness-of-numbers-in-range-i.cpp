class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        auto count = [&](string s)->void{
            int n = s.size();
            for(int i=1; i+1<n; i++)
            {
                ans += (s[i]>s[i-1] && s[i]>s[i+1]);
                ans += (s[i]<s[i-1] && s[i]<s[i+1]);
            }
        };

        for(int i=num1; i<=num2; i++)count(to_string(i));
        return ans;
    }
};