// Time: O(m * 4^n)
// Space: O(n)
// Algo intuition:
//      keep a counter for row and col and check at each number if the word
//      exists
class Solution {
private:
    bool backtrack(vector<vector<char>>& board, string& word, int r, int c,
                   int i) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        board[r][c] = '#';
        bool ans = backtrack(board, word, r + 1, c, i + 1) ||
                   backtrack(board, word, r - 1, c, i + 1) ||
                   backtrack(board, word, r, c + 1, i + 1) ||
                   backtrack(board, word, r, c - 1, i + 1);
        board[r][c] = word[i];
        return ans;
    }

public:
    int ROWS = 0;
    int COLS = 0;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; ++j) {
            for (int c = 0; c < COLS; ++j) {
                if (backtrack(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};