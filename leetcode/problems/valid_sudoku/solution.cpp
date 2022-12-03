class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> row(9), col(9), box(9);
            for (int j = 0; j < 9; j++)
                if (!isValid(board, row, i, j) || !isValid(board, col, j, i) || !isValid(board, box, i / 3 * 3 + j / 3, i % 3 * 3 + j % 3))
                    return false;
        }
        return true;
    }
private:
    bool isValid(vector<vector<char>>& board, vector<bool>& seen, int row, int col) {
        if (board[row][col] == '.')
            return true;
        if (seen[board[row][col] - '1'])
            return false;
        seen[board[row][col] - '1'] = true;
        return true;
    }
};