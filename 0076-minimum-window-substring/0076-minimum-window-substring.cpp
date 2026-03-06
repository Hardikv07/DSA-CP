class Solution {
public:
    string minWindow(string s, string t) {
         //your code goes here
         int hash[256] = {0};
         for(auto it : t)hash[it]++;
         int st = -1;
         int mn = INT_MAX;
         int count = 0;
         int l = 0;
         for(int i=0; i<s.size(); i++)
         {
            if(hash[s[i]]>0)
            {
                count++;
            }
            hash[s[i]]--;
            while(count == t.size())
            {
               if(i-l+1 < mn)
               {
                 mn = i-l+1;
                 st = l;
                                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    count--;
                }
                l++;
            }
         
         }
         return st==-1 ? "" : s.substr(st,mn);
    }
};