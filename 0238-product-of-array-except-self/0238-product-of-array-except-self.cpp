#define ll long
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<ll> suf(n),pre(n);
        pre[0]=v[0];
        for(int i=1; i<n; i++)pre[i]=pre[i-1]*v[i];
        suf[n-1]=v.back();
        for(int i =n-2; i>=0; i--)suf[i] = suf[i+1]*v[i];
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int num = 1;
            if(i)num *= pre[i-1];
            if(i+1 < n)num *= suf[i+1];
            ans[i] = num;
        }
        return ans;
    }
};