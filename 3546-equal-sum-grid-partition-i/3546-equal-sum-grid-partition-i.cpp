class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        long long totalSum = 0;
        
        // Calculate total sum
        for (auto &row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }
        
        // If total sum is odd, can't split equally
        if (totalSum % 2 != 0) return false;
        
        // Check horizontal cuts
        long long prefixSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                prefixSum += grid[i][j];
            }
            if (prefixSum == totalSum - prefixSum) {
                return true;
            }
        }
        
        // Check vertical cuts
        prefixSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                prefixSum += grid[i][j];
            }
            if (prefixSum == totalSum - prefixSum) {
                return true;
            }
        }
        
        return false;
    }
};