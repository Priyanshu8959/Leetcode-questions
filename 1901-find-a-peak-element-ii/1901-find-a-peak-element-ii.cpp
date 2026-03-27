class Solution {
public:
    int helper(vector<vector<int>>& mat, int col) {
        int index = 0;
        int maxValue = INT_MIN;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;
        int left = INT_MIN;
        int right = INT_MIN;
        while (low <= high) {
            int guess = low + (high - low) / 2;
            int row = helper(mat, guess);

            // prep for peak ele
            if (guess > 0) {
                left = mat[row][guess - 1];
            } else {
                left = INT_MIN;
            }
            if (guess < mat[0].size()-1) {
                right = mat[row][guess + 1];
            } else {
                right = INT_MIN;
            }

            // checking peak element
            if (left < mat[row][guess] && mat[row][guess] > right) {
                return {row, guess};
            } else if (left > mat[row][guess]) {
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }
        return {-1, -1};
    }
};