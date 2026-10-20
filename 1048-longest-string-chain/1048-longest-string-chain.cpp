
class Solution {
public:
    static bool myfunction(string s1, string s2) {
        return s1.length() < s2.length();
    }

    bool predecessor(string& prev, string& curr) {
        int n = prev.length();
        int m = curr.length();

        if (m - n != 1) {
            return false;
        }

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }

        return i == n;
    }

    int solve(vector<string>& words, int n, int prev, int curr,
              vector<vector<int>>& dp) {
        if (curr >= n) return 0;

        if (dp[prev + 1][curr] != -1) {
            return dp[prev + 1][curr];
        }

        int skip = solve(words, n, prev, curr + 1, dp);

        int take = 0;
        if (prev == -1 || predecessor(words[prev], words[curr])) {
            take = 1 + solve(words, n, curr, curr + 1, dp);
        }

        return dp[prev + 1][curr] = max(skip, take);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), myfunction);

        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return solve(words, n, -1, 0, dp);
    }
};
