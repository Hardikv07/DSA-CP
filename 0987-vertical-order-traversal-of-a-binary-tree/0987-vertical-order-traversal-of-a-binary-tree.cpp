/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,priority_queue<int,vector<int>,greater<int>>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto it = q.front();
                int x = it.second.first;
                int y = it.second.second;
                mpp[x][y].push(it.first->val);
                q.pop();
                if(it.first->left)
                {
                    q.push({it.first->left,{x-1,y+1}});
                }
                if(it.first->right)
                {
                    q.push({it.first->right,{x+1,y+1}});
                }
            }
        }
        vector<vector<int>> ans;
        for(auto &it : mpp)
        {
            vector<int> tmp;
            for(auto &j : it.second)
            {
               while(!j.second.empty())
              { tmp.push_back(j.second.top());
               j.second.pop();}
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};