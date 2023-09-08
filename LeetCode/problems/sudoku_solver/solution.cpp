class Solution {
    vector<vector<bool>> inRow, inCol, inBox;
public:
    Solution() : inRow(9, vector<bool>(9)), inCol(9, vector<bool>(9)), inBox(9, vector<bool>(9)) {}
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> unsolved;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    unsolved.push_back(i * 9 + j);
                else inRow[i][board[i][j] - '1'] = inCol[j][board[i][j] - '1'] = inBox[i / 3 * 3 + j / 3][board[i][j] - '1'] = true;
        reverse(unsolved.begin(), unsolved.end());
        solve(board, unsolved);
    }
private:
    bool solve(vector<vector<char>>& board, vector<int>& unsolved) {
        if (unsolved.empty())
            return true;
        int cell = unsolved.back(), row = cell / 9, col = cell % 9, box = row / 3 * 3 + col / 3;
        unsolved.pop_back();
        for (int i = 0; i < 9; i++) {
            if (inRow[row][i] || inCol[col][i] || inBox[box][i])
                continue;
            board[row][col] = '1' + i;
            inRow[row][i] = inCol[col][i] = inBox[box][i] = true;
            if (solve(board, unsolved))
                return true;
            board[row][col] = '.';
            inRow[row][i] = inCol[col][i] = inBox[box][i] = false;
        }
        unsolved.push_back(cell);
        return false;
    }
};