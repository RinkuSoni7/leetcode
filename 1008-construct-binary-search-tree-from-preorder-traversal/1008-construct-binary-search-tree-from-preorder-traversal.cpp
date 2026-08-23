class Solution {
public:

    TreeNode* insert(TreeNode* root, int val) {

      
        if (root == NULL) {
            return new TreeNode(val);
        }

   
        if (val < root->val) {
            root->left = insert(root->left, val);
        }

        
        else {
            root->right = insert(root->right, val);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = NULL;

        for (int i = 0; i < preorder.size(); i++) {
            root = insert(root, preorder[i]);
        }

        return root;
    }
};