class Solution {
    vector<pair<int, int>> dir = {
        { -1, 0 },
        { 0, 1 },
        { 1, 0 },
        { 0, -1 }
    };
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (exist(board, i, j, 0, word))
                    return true;
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, int row, int col, int i, string& word) {
        if (i >= word.size())
            return true;
        if (row < 0 || row >= board.size())
            return false;
        if (col < 0 || col >= board[row].size())
            return false;
        char c = board[row][col];
        if (c == '#')
            return false;
        if (c != word[i])
            return false;
        board[row][col] = '#';
        for (auto [di, dj] : dir)
            if (exist(board, row + di, col + dj, i + 1, word))
                return true;
        board[row][col] = c;
        return false;
    }
};