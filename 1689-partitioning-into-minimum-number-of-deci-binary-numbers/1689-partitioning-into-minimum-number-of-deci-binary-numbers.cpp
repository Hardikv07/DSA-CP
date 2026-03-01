class Solution {
public:
    /*
    82734
    11111
    11111
    11111
    11111
    11111
    11111
    11111
    77777
    
    */
    int minPartitions(string n) {
        char ch = '0';
        for(auto it : n)ch = max(ch,it);
        return ch-'0';
    }
};