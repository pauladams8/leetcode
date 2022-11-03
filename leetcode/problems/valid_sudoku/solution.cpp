class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            vector<bool> seen(9);
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                if (seen[board[row][col] - '1'])
                    return false;
                seen[board[row][col] - '1'] = true;
            }
        }
        for (int col = 0; col < 9; col++) {
            vector<bool> seen(9);
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;
                if (seen[board[row][col] - '1'])
                    return false;
                seen[board[row][col] - '1'] = true;
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> seen(9);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[row + i][col + j] == '.')
                            continue;
                        if (seen[board[row + i][col + j] - '1'])
                            return false;
                        seen[board[row + i][col + j] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};