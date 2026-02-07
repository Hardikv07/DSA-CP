class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        stack<char> st;
        int n = (int)s.size();
        for(int i=0; i<n; i++)
        {
            if(!st.empty() && st.top()=='b' && s[i]=='a')
            {
                st.pop();
                ans++;
            }
            else
            {
                st.push(s[i]);
            }
        }
        return ans;
    }
};