class Solution {
public:
    int binaryGap(int n) {
        string str = "";
        while(n>0)
        {
            str += '0'+(n%2);
            n >>= 1;
        }
        reverse(str.begin(),str.end());
        int ans = 0,prev=0;
        for(int i=0; i<(int)str.size(); i++)
        {
            if(str[i]=='1')
            {
                 ans = max(abs(prev-i),ans);
                 prev = i;
            }
        }
        return ans;
    }
};