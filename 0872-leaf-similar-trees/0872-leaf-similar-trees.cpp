class Solution {
public:

    void leaf(TreeNode* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }

        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
            return;
        }

        
        leaf(root->left, ans);

        
        leaf(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> ans1;
        vector<int> ans2;

        leaf(root1, ans1);
        leaf(root2, ans2);

        return ans1 == ans2;
    }
};