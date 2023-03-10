class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<bool>> blocked(n, vector<bool>(n));
        vector<vector<bool>> used(n, vector<bool>(n));
        vector<vector<string>> boards;
        solveNQueens(n, board, blocked, used, boards);
        return boards;
    }
private:
    void solveNQueens(int n, vector<string>& board, vector<vector<bool>>& blocked, vector<vector<bool>>& prevUsed, vector<vector<string>>& boards) {
        if (n == 0) {
            boards.push_back(board);
            return;
        }
        vector<vector<bool>> used(board.size(), vector<bool>(board.size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (blocked[i][j])
                    continue;
                prevUsed[i][j] = true;
                if (used[i][j])
                    continue;
                board[i][j] = 'Q';
                vector<pair<int, int>> directions = {
                    { -1, 0 },
                    { -1, 1 },
                    { 0, 1 },
                    { 1, 1 },
                    { 1, 0 },
                    { 1, -1 },
                    { 0, -1 },
                    { -1, -1 }
                };
                stack<pair<int, int>> stack;
                for (auto [di, dj] : directions) {
                    int ii = i, jj = j;
                    while (ii >= 0 && jj >= 0 && ii < board.size() && jj < board[ii].size()) {
                        if (!blocked[ii][jj]) {
                            blocked[ii][jj] = true;
                            stack.push({ ii, jj });
                        }
                        ii += di;
                        jj += dj;
                    }
                }
                solveNQueens(n - 1, board, blocked, used, boards);
                board[i][j] = '.';
                while (!stack.empty()) {
                    auto [ii, jj] = stack.top();
                    stack.pop();
                    blocked[ii][jj] = false;
                }
            }
        }
    }
};