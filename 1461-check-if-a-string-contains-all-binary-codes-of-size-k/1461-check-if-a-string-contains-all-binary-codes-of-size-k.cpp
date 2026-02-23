class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<string,int> mpp;
        int n = (int)s.size();
        for(int i=0; i<=n-k; i++)
        {
            // if(k+i < n)
            mpp[s.substr(i,k)]++;
        }
        // for(auto it : mpp)cout << it.first << " ";
        return (mpp.size() == (1<<k));
    }
};