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
bool onetree(TreeNode*&root){
    if(root==NULL){
        return false;
    }
    if(root->val==1){
        return true;
    }

    return onetree(root->left) || onetree(root->right);
}
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        if(!onetree(root->left)){
           root->left = NULL;
        }

        if(!onetree(root->right)){
          root->right = NULL;
        }

        root->left=pruneTree(root->left);
       root->right= pruneTree(root->right);


        if(root->left==NULL && root->right==NULL && root->val==0){
            return NULL;
        }
        return root;
    }
};