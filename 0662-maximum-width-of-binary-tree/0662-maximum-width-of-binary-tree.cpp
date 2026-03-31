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
 #define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            int mmin = q.front().second;
            int first = 0,last = 0;
            for(int i=0; i<sz; i++)
            {
                
                auto it = q.front();
                int idx = it.second - mmin;
                q.pop();
                if(i==0)
                {
                    first = idx;
                }
                if(i==sz-1)
                {
                    last = idx;
                }
                if(it.first && it.first->left)
                {
                    q.push({it.first->left,2LL*(idx)+1});
                }
                if(it.first && it.first->right)
                {
                    q.push({it.first->right,2LL*(idx)+2});
                }
            }
                ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};