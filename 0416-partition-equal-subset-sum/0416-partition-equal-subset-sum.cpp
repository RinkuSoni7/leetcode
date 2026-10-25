
class Solution {
public:
    bool solve(vector<int>& nums, int idx, int a, vector<vector<int>>& dp) {
        if (a == 0) return true;

        if (idx >= nums.size() || a < 0) return false;

        if (dp[idx][a] != -1) {
            return dp[idx][a];
        }

        bool take = solve(nums, idx + 1, a - nums[idx], dp);
        bool notake = solve(nums, idx + 1, a, dp);

        return dp[idx][a] = take || notake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int a = sum / 2;

        vector<vector<int>> dp(n, vector<int>(a + 1, -1));

        return solve(nums, 0, a, dp);
    }
};
