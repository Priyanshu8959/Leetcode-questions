class Solution {
public:
    void solve(int col, int n, vector<int>& ud, vector<int>& ld, vector<int>& leftrow,
               vector<vector<string>>& ans, vector<string>& board) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && ld[row + col] == 0 && ud[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;

                solve(col + 1, n, ud, ld, leftrow, ans, board);

                board[row][col] = '.';
                leftrow[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> leftrow(n, 0), ld(2 * n - 1, 0), ud(2 * n - 1, 0);

        solve(0, n, ud, ld, leftrow, ans, board);
        return ans;
    }
};
