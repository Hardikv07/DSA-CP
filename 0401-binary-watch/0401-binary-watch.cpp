class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i=0; i<12; i++)
        {
            for(int j=0; j<60; j++)
            {
                 int sbm = __builtin_popcount(j);
                 int sbh = __builtin_popcount(i);
                 if(sbm+sbh == turnedOn)
                 {
                    string tmp = to_string(i) + ":";
                    if(j/10)
                    {
                        tmp += to_string(j);
                    }
                    else
                    {
                        tmp += "0"+to_string(j);
                    }
                     ans.push_back(tmp);
                 }    
            }
        }
        return ans;
    }
};