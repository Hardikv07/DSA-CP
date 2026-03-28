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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> solve = [&](TreeNode* root)->int{
              if(root==nullptr)return 0;
              int lft = max(0,solve(root->left));
              int rht = max(0,solve(root->right));
              ans = max(ans,root->val+lft+rht);
              return root->val + max(lft,rht);
        };
        solve(root);
        return ans;
    }
};