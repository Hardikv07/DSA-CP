class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
         auto mxGp = [&](vector<int>& bars){
            if(bars.empty()) return 1; 
            sort(bars.begin(), bars.end());
            int best = 1, cnt = 1;
            for(int i = 1; i < bars.size(); i++){
                if(bars[i] == bars[i-1] + 1) {
                    cnt++;
                    best = max(best, cnt);
                } else {
                    cnt = 1;
                }
            }
            return best + 1;
        };

        int hg = mxGp(hBars);
        int vg = mxGp(vBars);
        hg= min(hg, vg);
        return hg * hg;
    }
};