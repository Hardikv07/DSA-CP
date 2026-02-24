class Solution {
public:

    void solve(TreeNode* root, int curr, int &sum)
    {
        if(!root) return;

        curr = curr * 2 + root->val;   

        if(!root->left && !root->right)
        {
            sum += curr;   
            return;
        }

        solve(root->left, curr, sum);
        solve(root->right, curr, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};