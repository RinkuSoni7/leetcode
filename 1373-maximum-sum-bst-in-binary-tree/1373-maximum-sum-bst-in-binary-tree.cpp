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

    class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int sum;
    };

    info solve(TreeNode* root, int &ans){
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info curr;

        // check BST condition
        if(left.isBST && right.isBST &&
           root->val > left.maxi && root->val < right.mini){

            curr.isBST = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.maxi = max(root->val, right.maxi);
            curr.mini = min(root->val, left.mini);

            ans = max(ans, curr.sum);   // 🔥 update max sum
        }
        else{
            curr.isBST = false;
            curr.sum = 0; // important
            curr.maxi = INT_MAX;
            curr.mini = INT_MIN;
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};