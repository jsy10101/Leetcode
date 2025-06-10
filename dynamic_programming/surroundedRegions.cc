// Time: O(m * n)
// Space: O(m * n)
// Algorithm intuition:
//      - reverse thinking
//      - capture everything but unsurrounded regions
class Solution {
   private:
    int ROWS = 0;
    int COLS = 0;

    void capture(vector<vector<char>>& board, int row, int col) {
        // base case
        if (row < 0 || row > ROWS - 1 ||
            col < 0 || col > COLS - 1 ||
            board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'T';

        capture(board, row + 1, col);
        capture(board, row - 1, col);
        capture(board, row, col + 1);
        capture(board, row, col - 1);
    }

   public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        // 1. run dfs on the edge cells with 'O' (unsurrounded region) and mark it as a temp region
        for (int r = 0; r < ROWS; ++r) {
            if (board[r][0] == 'O') {
                capture(board, r, 0);
            }
            if (board[r][COLS - 1] == 'O') {
                capture(board, r, COLS - 1);
            }
        }

        for (int c = 0; c < COLS; ++c) {
            if (board[0][c] == 'O') {
                capture(board, 0, c);
            }
            if (board[ROWS - 1][c] == 'O') {
                capture(board, ROWS - 1, c);
            }
        }

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                // 2. after the temporary regions have been marked, convert all the regions with 'O' (now these regions are SURROUNDED since we marked the unsurrounded regions as 'T')
                // convert 'O' -> 'X'
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                // 3. lastly since all the surrounded regions have been marked, convert the temporary unsurrounded regiongs back to 'O's
                // convert 'T' -> 'O'
                if (board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};