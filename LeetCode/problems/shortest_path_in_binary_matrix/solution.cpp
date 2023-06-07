class Solution {
    vector<pair<int, int>> dir = {
        { -1, 0 },
        { -1, 1 },
        { 0, 1 },
        { 1, 1 },
        { 1, 0 },
        { 1, -1 },
        { 0, -1 },
        { -1, -1 }
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), length = 1;
        queue<pair<int, int>> q, next;
        if (!grid[0][0])
            q.push({ 0, 0 }), grid[0][0] = 1;
        while (!q.empty()) {
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                if (i == n - 1 && j == n - 1)
                    return length;
                for (auto [di, dj] : dir) {
                    int ii = i + di, jj = j + dj;
                    if (ii < 0 || ii >= n || jj < 0 || jj >= n || grid[ii][jj])
                        continue;
                    next.push({ ii, jj });
                    grid[ii][jj] = 1;
                }
            }
            length++;
            swap(q, next);
        }
        return -1;
    }
};