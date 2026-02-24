class Solution {
public:
    /*
    
    do op
    not do op
    
    */

   

    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        int n = (int)exp.size();
        for(int i=0; i<n; i++)
        {
            if(exp[i]=='+' || exp[i] == '-' || exp[i] == '*')
            {
                vector<int> res1 = diffWaysToCompute(exp.substr(0,i));
                vector<int> res2 = diffWaysToCompute(exp.substr(i+1));
                for(auto it : res1)
                {
                    for(auto jt : res2)
                    {
                        if(exp[i]=='+')
                        {
                            ans.push_back(it+jt);
                        }
                        else if(exp[i] == '-')
                        {
                            ans.push_back(it-jt);
                        }
                        else
                        {
                             ans.push_back(it*jt);
                        }
                    }
                }
            }
        }
        if(ans.empty())
        {
            ans.push_back(stoi(exp));
        }
        return ans;
    }
};