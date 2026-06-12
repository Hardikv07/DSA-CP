class Solution {
public:
    string shortestPalindrome(string s) {
         string rev = s;
         reverse(rev.begin(),rev.end());
         string tmp = s+'$'+rev;
        int n = tmp.size();

        vector<int> lps(n);

        int i=1,j=0;
        while(i<n)
        {
            if(tmp[i]==tmp[j])
            {
                lps[i] = j+1;
                j++,i++;
            }
            else
            {
                while(j>0 && tmp[j]!=tmp[i])
                {
                    j = lps[j-1];
                }
                if(tmp[i]==tmp[j])
                {
                    lps[i] = j+1;
                    j++;
                }

               i++;
            }
        }
        // cout << tmp << "\n";
        // for(auto it : lps)cout << it << " ";
        // return "Hardik";
        int tober = s.size() - lps.back();
        string add = rev.substr(0,tober);
        return add + s;
    }
};