class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> unsolved;
        map<string, bool> seen;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    unsolved.push_back(i * 9 + j);
                } else {
                    seen[hash("row", i, board[i][j] - '0')] = true;
                    seen[hash("col", j, board[i][j] - '0')] = true;
                    seen[hash("box", i / 3 * 3 + j / 3, board[i][j] - '0')] = true;
                }
            }
        }
        solve(board, unsolved, seen);
    }
    
    bool solve(vector<vector<char>>& board, vector<int>& unsolved, map<string, bool>& seen) {
        if (unsolved.empty()) {
            return true;
        }
        int cell = unsolved.back(), row = cell / 9, col = cell % 9, box = row / 3 * 3 + col / 3;
        unsolved.pop_back();
        for (int i = 1; i <= 9; i++) {
            if (!seen[hash("row", row, i)] && !seen[hash("col", col, i)] && !seen[hash("box", box, i)]) {
                board[row][col] = '0' + i;
                seen[hash("row", row, i)] = true;
                seen[hash("col", col, i)] = true;
                seen[hash("box", box, i)] = true;
                if (solve(board, unsolved, seen)) {
                    return true;
                }
                board[row][col] = '.';
                seen[hash("row", row, i)] = false;
                seen[hash("col", col, i)] = false;
                seen[hash("box", box, i)] = false;
            }
        }
        unsolved.push_back(cell);
        return false;
    }
    
    string hash(string type, int id, int digit) {
        return type + "," + to_string(id) + "," + to_string(digit);
    }
};