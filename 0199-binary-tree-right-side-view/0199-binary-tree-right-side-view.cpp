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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);
        vector<int>result;
        while(!q.empty()){
            int n=q.size();
            // vector<int>ans;
            TreeNode*temp;
            while(n--){
                temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                }
                
            }
            result.push_back(temp->val);

        }
        return result;

    }
};