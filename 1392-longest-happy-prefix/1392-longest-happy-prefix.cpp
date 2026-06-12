class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int i=1,j=0;
        vector<int> lps(n);
        while(i<n)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                i++,j++;
            }
            else
            {
                while(j>0 && s[i]!=s[j])
                {
                    j = lps[j-1];
                }
                if(s[i]==s[j])
                {
                    lps[i]=j+1;
                    j++;
                }
                i++;
            }
        }
        return s.substr(0,lps.back());
    }
};