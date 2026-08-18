class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxwidth = 0;

        while(!q.empty()){

            int n = q.size();

            long long first = q.front().second;
            long long last = q.back().second;

            maxwidth = max(maxwidth, last - first + 1);

            while(n--){

                TreeNode* temp = q.front().first;
                long long idx = q.front().second;

                q.pop();

                // Normalize index
                idx = idx - first;

                if(temp->left){
                    q.push({temp->left, 2 * idx + 1});
                }

                if(temp->right){
                    q.push({temp->right, 2 * idx + 2});
                }
            }
        }

        return maxwidth;
    }
};