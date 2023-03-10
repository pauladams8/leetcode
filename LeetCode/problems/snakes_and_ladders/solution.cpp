class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), n2 = n * n;
        queue<int> q;
        vector<bool> seen(n2 + 1);
        q.push(1);
        seen[1] = true;
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int square = q.front();
                q.pop();
                if (square == n2)
                    return moves;
                for (int next = square + 1; next <= min(square + 6, n2); next++) {
                    int row = (next - 1) / n, col = (next - 1) % n, dest = board[~row + n][row % 2 ? ~col + n : col];
                    dest = dest != -1 ? dest : next;
                    if (seen[dest])
                        continue;
                    q.push(dest);
                    seen[dest] = true;
                }
            }
            moves++;
        }
        return -1;
    }
};