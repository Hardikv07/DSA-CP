class Solution {
public:
   /*
  
   
   */



    int countBinarySubstrings(string s) {
        int ans = 0;
        int cnt = 1;
        int n = (int)s.size();
        int pre = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==s[i-1])cnt++;
            else
            {
                ans += min(cnt,pre);
                pre = cnt;
                cnt = 1;
            }
        }
        ans += min(cnt,pre);
        return ans;
    }
};