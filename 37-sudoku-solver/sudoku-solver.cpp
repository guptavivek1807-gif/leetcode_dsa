class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Mistake 3 fixed: check for '.' instead of ' '
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isvalid(board, i, j, c)) {
                            board[i][j] = c;
                            
                            if (solve(board))
                                return true;
                            
                            // Backtrack
                            board[i][j] = '.';
                        }
                    }
                    return false; // Couldn't place 1-9 in this empty cell
                }
            }
        }
        return true; // All cells filled successfully
    }

    // Mistake 1 fixed: isvalid is now a separate method
    bool isvalid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check column
            if (board[i][col] == c)
                return false;

            // Check row
            if (board[row][i] == c)
                return false;

            // Check 3x3 sub-grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true; // Mistake 2 fixed: returns true if valid
    }
};