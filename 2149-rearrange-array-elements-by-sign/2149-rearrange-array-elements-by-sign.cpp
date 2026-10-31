class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            } else {
                pos.push_back(nums[i]);
            }
        }

        int m = pos.size();
        int o = neg.size();

        int i = 0, j = 0, k = 0;

        while(i < n) {
            if(i % 2 == 0) {
                ans[i] = pos[j++];
            } else {
                ans[i] = neg[k++];
            }
            i++;  // Important: increment index
        }

        return ans;
    }
};