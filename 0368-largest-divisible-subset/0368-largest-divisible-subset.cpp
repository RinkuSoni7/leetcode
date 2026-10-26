
class Solution {
public:
    int solve(vector<int>& nums, int idx, int prev, vector<vector<int>>& dp) {
        if (idx >= nums.size()) return 0;

        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        int take = 0;

        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            take = 1 + solve(nums, idx + 1, idx, dp);
        }

        int notake = solve(nums, idx + 1, prev, dp);

        return dp[idx][prev + 1] = max(take, notake);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        solve(nums, 0, -1, dp);

        vector<int> result;
        int prev = -1;

        for (int idx = 0; idx < n; idx++) {
            int take = 0;

            if (prev == -1 || nums[idx] % nums[prev] == 0) {
                take = 1 + solve(nums, idx + 1, idx, dp);
            }

            int notake = solve(nums, idx + 1, prev, dp);

            if ((prev == -1 || nums[idx] % nums[prev] == 0) && take >= notake) {
                result.push_back(nums[idx]);
                prev = idx;
            }
        }

        return result;
    }
};
