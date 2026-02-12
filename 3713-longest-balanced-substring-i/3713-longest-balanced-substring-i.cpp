class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
           map<char, int> mp;
            
            for(int j = i; j < n; j++) {
                mp[s[j]]++;
                
                int sm = -1;
                bool f = true;
                
                for(auto &p : mp) {
                    if(sm == -1) {
                        sm = p.second;
                    } else if(sm != p.second) {
                        f = false;
                        break;
                    }
                }
                
                if(f) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};
