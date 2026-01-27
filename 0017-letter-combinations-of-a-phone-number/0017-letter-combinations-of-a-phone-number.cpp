class Solution {
public:
  vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
     vector<string> ans;
     void solve(string &dig,int n,string s,int idx)
     {
        if(idx == n)
        {
            if(!s.empty()  && s.size()==n)
            ans.push_back(s);
            return;
        }
        string letters = mp[dig[idx] - '0'];
        for(int i=0; i<letters.size(); i++){
            solve(dig,n,s+letters[i],idx+1);     
        }
     }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(digits == "")return ans;
        solve(digits,n,"",0);
        return ans;
    }
};