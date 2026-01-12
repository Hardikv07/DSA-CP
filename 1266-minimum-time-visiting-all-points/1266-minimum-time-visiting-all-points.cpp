class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0];
        int y = points[0][1];
        int idx = 0;
        int n = points.size();
        int ans = 0;
        while (idx < n) {
            int cnt = 0;
            if (points[idx][0] < x) {
                while (points[idx][0] < x) {
                    ans++;
                    x--;
                    cnt++;
                }
                if (points[idx][1] < y) {
                    while (points[idx][1] < y) {
                        ans += cnt <= 0;
                        cnt--;
                        y--;
                    }
                } else if (points[idx][1] > y) {
                    while (points[idx][1] > y) {
                        ans += cnt <= 0;
                        cnt--;
                        y++;
                    }
                }
            } else {
                while (points[idx][0] > x) {
                    ans++;
                    x++;
                    cnt++;
                }
                if (points[idx][1] < y) {
                    while (points[idx][1] < y) {
                        ans += cnt <= 0;
                        cnt--;
                        y--;
                    }
                } else if (points[idx][1] > y) {
                    while (points[idx][1] > y) {
                        ans += cnt <= 0;
                        cnt--;
                        y++;
                    }
                }
            }
            idx++;
        }
        return ans;
    }
};