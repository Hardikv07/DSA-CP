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
    bool isSymmetric(TreeNode* root) {
        function<bool(TreeNode*,TreeNode*)> check = [&](TreeNode* tmp1,TreeNode* tmp2)->bool{
             if(!tmp1 && !tmp2)return true;
             if(!tmp1 || !tmp2)return false;
             if(tmp1->val != tmp2->val)return false;
             return check(tmp1->left,tmp2->right) && check(tmp1->right,tmp2->left); 
        };
        return check(root->left,root->right);
    }
};