class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {

        //your code goes here
        int n = Intervals.size();
        auto cmp = [&](vector<int> a,vector<int> b)->bool{
          return a[1]<b[1];
        };
        sort(Intervals.begin(),Intervals.end(),cmp);
        int del = 0;
        int cur = Intervals[0][1];
        for(int i=1; i<n; i++)
        {
          if(cur > Intervals[i][0])
          {
            del++;
          }
          else
          {
            cur = Intervals[i][1];
          }
        }
        return del;
    
    }
};