class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int row, int col, int index) {

        // Entire word matched
        if (index == word.length()) {
            return true;
        }

        // Boundary or character mismatch
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols ||
            board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);

        // Backtracking: restore the cell
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == word[0] &&
                    dfs(board, word, row, col, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};