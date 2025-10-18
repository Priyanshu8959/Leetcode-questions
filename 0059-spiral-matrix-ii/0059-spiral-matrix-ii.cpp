class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int value = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++)
                result[top][i] = value++;
            top++;

            for (int i = top; i <= bottom; i++)
                result[i][right] = value++;
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    result[bottom][i] = value++;
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result[i][left] = value++;
                left++;
            }
        }

        return result;
    }
};
