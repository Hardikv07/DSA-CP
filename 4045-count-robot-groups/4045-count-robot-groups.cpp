class Solution {
public:
    int countGroups(vector<int>& p, vector<int>& s, int d) {
       int n = p.size();
       int ans = n;
       int mxSofar = s.back();
       for(int i=n-1; i>0; i--)
       {
           if(p[i]-p[i-1] <= d)ans--;
           else if(s[i-1] > mxSofar)ans--;
           else mxSofar = s[i-1];
       }
       return ans;
    }
};