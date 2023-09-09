class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(board, ans, 0);
        return ans;
    }
private:
    void solve(vector<string>& board, vector<vector<string>>& ans, int row) {
        int n = board.size();
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            solve(board, ans, row + 1);
            board[row][col] = '.';
        }
    }
private:
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; i++)
            if (board[row][i] == 'Q' || board[i][col] == 'Q')
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
};