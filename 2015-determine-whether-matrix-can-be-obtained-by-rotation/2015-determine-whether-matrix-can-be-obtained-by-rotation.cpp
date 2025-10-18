class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        for (int r = 0; r < 4; r++) {
            if (mat == target) return true;

            // rotate 90 degrees clockwise in-place (without extra matrix)
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]); // transpose
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());  
            }
        }

        return false;
    }
};
