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

   in level order traversal insert node that appears at last in every level by y


 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         map<int,int> mpp;
         queue<pair<TreeNode*,int>> q;
         q.push({root,0});
         while(!q.empty())
         {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto it = q.front();
                q.pop();
                if(it.first)
                mpp[it.second] = it.first->val;
                if(it.first && it.first->left)
                {
                    q.push({it.first->left,it.second+1});
                }
                if(it.first && it.first->right)
                {
                    q.push({it.first->right,it.second+1});
                }
            }
         }
         vector<int> ans;
         for(auto it : mpp)ans.push_back(it.second);
         return ans;
    }
};