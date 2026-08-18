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
void solve(TreeNode* root,int &level,int &l){
    if(root==NULL){
        return ;
    }
    queue<TreeNode*>q;
    q.push(root);
    int maxsum=INT_MIN;
     
    while(!q.empty()){
        int n=q.size();
        int sum=0;
        while(n--){
         TreeNode*temp=q.front();
            sum+=temp->val;
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(sum>maxsum){
        maxsum=sum;
        level=l;
       }

        l++;
        }


    }

    int maxLevelSum(TreeNode* root) {
        int level=1;
        int l=1;
        solve(root,level,l);
        return level;
    }
};