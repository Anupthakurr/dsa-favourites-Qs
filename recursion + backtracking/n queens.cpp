qs link ------>   https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int dupRow = row;
        int dupCol = col;

        // Check upper-left diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Reset to original values
        row = dupRow;
        col = dupCol;

        // Check left side
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Reset to original values
        row = dupRow;
        col = dupCol;

        // Check lower-left diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void solve(int col, vector<string> board, vector<vector<string>>& ans, int n) {
        if (col == n) {  // All queens are placed
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';  // Place the queen
                solve(col + 1, board, ans, n);  // Recur for next column
                board[row][col] = '.';  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  // Create an n x n board filled with '.'
        solve(0, board, ans, n);
        return ans;
    }
};
