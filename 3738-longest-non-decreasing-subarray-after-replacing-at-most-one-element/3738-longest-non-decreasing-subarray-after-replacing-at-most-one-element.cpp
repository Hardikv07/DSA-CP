class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int ans = 1;
        int n = v.size();
        if (n <= 2) return n;

        vector<int> pre(n,1),suf(n,1);
        for(int i=1; i<n; i++)
            {
                if(v[i]>=v[i-1])
                {
                    pre[i]= pre[i-1]+1;
                }
            }
        for(int j=n-2; j>=0; j--)
            {
                if(v[j]<=v[j+1])suf[j]=suf[j+1]+1;
            }
        for(auto it : pre)ans = max(ans,it);
        for(auto it : suf)ans = max(ans,it);
        for(int i=1; i+1<n; i++)
            {
                if(v[i-1] <= v[i+1])
                 ans = max(ans, pre[i - 1] + suf[i + 1] + 1);
                else
                {
                   ans = max(ans, max(pre[i - 1] + 1, suf[i + 1] + 1));
                }
            }
        ans = max(ans, suf[1] + 1);      
        ans = max(ans, pre[n-2] + 1);      
        if(ans>n)ans=n;
        return ans;
    }
};