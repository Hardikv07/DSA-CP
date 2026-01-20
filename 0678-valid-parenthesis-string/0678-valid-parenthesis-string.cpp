class Solution {
public:
    bool checkValidString(string s) {
        int mxO=0,mnO=0;
        int n = (int)s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                mxO++,mnO++;
            }
            else if(s[i]==')')
            {
                mnO--,mxO--;
            }
            else
            {
                mnO--,
                mxO++;
            }
            if(mxO<0)return false;
            if(mnO<0)mnO=0;
        }
        return !mnO;
    }
};