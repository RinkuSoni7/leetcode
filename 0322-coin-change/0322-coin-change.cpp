class Solution {
public:
    int solve(vector<int>& coins, int i, int amount,
              vector<vector<int>>& dp) {

        // Exact amount formed
        if (amount == 0)
            return 0;

        // No coins left
        if (i == coins.size())
            return INT_MAX;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Exclude current coin
        int exclude = solve(coins, i + 1, amount, dp);

        // Include current coin
        int include = INT_MAX;

        if (coins[i] <= amount) {
            int result = solve(coins, i, amount - coins[i], dp);

            if (result != INT_MAX)
                include = result + 1;
        }

        return dp[i][amount] = min(include, exclude);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(
            coins.size(),
            vector<int>(amount + 1, -1)
        );

        int ans = solve(coins, 0, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};