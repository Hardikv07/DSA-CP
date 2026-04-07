/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator{
	public:
        vector<int> v;
        int idx=0;
		BSTIterator(TreeNode* root){
			function<void(TreeNode*)> inorder = [&](TreeNode* node)->void{
                  if(!node)return;
                  inorder(node->left);
                  v.push_back(node->val);
                  inorder(node->right);
            };
            inorder(root);
            idx=0;
		}
		
		bool hasNext(){
			return idx < (int)v.size();            
		}
		
		int next(){
             int tober = v[idx];
             idx++;
             return tober;
		}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */