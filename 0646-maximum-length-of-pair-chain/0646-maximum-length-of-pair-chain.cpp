class Solution {
public:
    int findLongestChain(vector<vector<int>>& v) {
         auto cmp = [&](vector<int> a1,vector<int> a2)->bool{
           return a1[1]<a2[1];
        };
        sort(v.begin(),v.end(),cmp);
        int prev=INT_MIN;
        int cnt=0;
        int n = v.size();
        for(int i=0; i<n; i++)
        {
          if(v[i][0] > prev)
          {
            cnt++;
            prev = v[i][1];
          }
          //  prev = v[i].second;
         
        }
        return cnt;
    }
};