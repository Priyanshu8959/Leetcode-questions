class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);  // Memoization array
        return helper(n, dp);
    }

    int helper(int n, vector<int>& dp) {
        if (n == 0 || n == 1) return 1;

        if (dp[n] != -1) return dp[n];  // Already computed

        // Store and return result
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
};
