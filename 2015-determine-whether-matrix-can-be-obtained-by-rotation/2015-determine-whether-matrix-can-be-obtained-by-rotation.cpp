class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // 90 degree roattion
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for (int r = 0; r < 4; r++) {
            if (mat == target) {
                return true;
                break;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rotated[j][n - i - 1] = mat[i][j];
                }
            }
            mat = rotated;
        }

        return false;
    }
};