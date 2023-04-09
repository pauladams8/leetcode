class Solution {
    vector<pair<int, int>> dir = {
        { -1, -1 },
        { -1, 0 },
        { -1, 1 },
        { 0, -1 },
        { 0, 1 },
        { 1, -1 },
        { 1, 0 },
        { 1, 1 }
    };
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int count = 0;
                for (auto [di, dj] : dir)
                    if (isAlive(board, i + di, j + dj))
                        count++;
                board[i][j] |= nextState(board[i][j] & 1, count) << 1;
            }
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                board[i][j] >>= 1;
    }
private:
    bool isAlive(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && board[i][j] & 1;
    }
    
    int nextState(int state, int count) {
        if (!state) return count == 3;
        if (count == 2 || count == 3) return 1;
        return 0;
    }
};