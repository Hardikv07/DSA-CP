class Solution {
public:
    bool queryString(string s, int n) {
        set<int> st;
        auto conv = [&](string str)->void{
             int num = 0;
            for(int i = 0; i < (int)str.size(); i++) {
                num = (num << 1) + (str[i] - '0'); 
            }
            st.insert(num);
        };
        for(int i=0; i<(int)s.size(); i++)
        {
            for(int j=i; j<min(i+10,(int)s.size()); j++)
            {
                conv(s.substr(i,j-i+1));
            }
        }
        for(auto it : st)cout << it << " ";
        for(int i=1; i<=n; i++)if(!st.count(i))return false;
        return true;
        
    }
};