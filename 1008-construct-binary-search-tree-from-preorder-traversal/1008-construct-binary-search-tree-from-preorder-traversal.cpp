class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int& idx, int lower, int upper) {

        if (idx >= preorder.size())
            return NULL;

    
        if (preorder[idx] < lower || preorder[idx] > upper)
            return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);

        
        idx++;

 
        root->left = solve(preorder, idx, lower, root->val);

      
        root->right = solve(preorder, idx, root->val, upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int lower = INT_MIN;
        int upper = INT_MAX;
        int idx = 0;

        return solve(preorder, idx, lower, upper);
    }
};