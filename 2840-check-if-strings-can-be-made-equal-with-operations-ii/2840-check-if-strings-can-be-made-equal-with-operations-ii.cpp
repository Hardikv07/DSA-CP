class Solution {
public:
    /*
    1 2 3 4 5 6 7 8 9 10

    1 3 5 7 9
    2 4 6 8 10


    */

    bool checkStrings(string s1, string s2) {
        multiset<char> mt;
        int n = s1.size();
        vector<int> freq(26);
        for (int i = 0; i < n; i += 2)
            freq[s1[i] - 'a']++;
        for (int i = 0; i < n; i += 2)
            freq[s2[i] - 'a']--;
        if (count(freq.begin(), freq.end(), 0) != 26)
            return false;
        for (int i = 1; i < n; i += 2)
            freq[s1[i] - 'a']++;
        for (int i = 1; i < n; i += 2)
            freq[s2[i] - 'a']--;
        if (count(freq.begin(), freq.end(), 0) != 26)
            return false;
        return true;
    }
};