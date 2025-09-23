class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

         vector<vector<vector<vector<int>>>> t(n + 1, vector<vector<vector<int>>>(target + 1));

        // Base cases
        for (int i = 0; i <= n; i++) {
            t[i][0] = { { } };   // ek empty combination ban sakta hai sum 0 ke liye
        }
        for (int j = 1; j <= target; j++) {
            t[0][j] = { };       // 0 candidates se positive sum nahi ban sakta
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                // Exclude current candidate
                t[i][j] = t[i-1][j];

                // Include current candidate (unlimited usage)
                if (candidates[i-1] <= j) {
                    for (auto comb : t[i][j - candidates[i-1]]) {
                        comb.push_back(candidates[i-1]);
                        t[i][j].push_back(comb);
                    }
                }
            }
        }

        return t[n][target];
    }
};
