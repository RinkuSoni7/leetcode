
class Solution {
public:
    int solve(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (idx >= nums.size()) return 0;

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int take = solve(nums, target - nums[idx], 0, dp);
        int notake = solve(nums, target, idx + 1, dp);

        return dp[idx][target] = take + notake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(nums, target, 0, dp);
    }
};
