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
// vector<vector<int>>result;

void solve(TreeNode* &root, int targetSum,vector<int>&temp,vector<vector<int>> &result,int sum){

if(root==NULL){
    return;
}
     sum=sum+root->val;
    temp.push_back(root->val);

    if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            result.push_back(temp);
        }}else{
            solve(root->left,targetSum,temp,result,sum);
            solve(root->right,targetSum,temp,result,sum);

        }
    
    temp.pop_back();
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>result;
        solve(root,targetSum,temp,result,0);

        return result;
    }
};