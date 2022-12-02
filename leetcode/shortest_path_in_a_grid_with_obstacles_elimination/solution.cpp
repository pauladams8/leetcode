class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<tuple<int, int, int>> q;
        vector<vector<vector<bool>>> seen(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(k + 1)));
        q.push({ 0, 0, k });
        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [row, col, ob] = q.front();
                q.pop();
                if (row < 0 || row >= grid.size())
                    continue;
                if (col < 0 || col >= grid[row].size())
                    continue;
                if (seen[row][col][ob])
                    continue;
                seen[row][col][ob] = true;
                if (grid[row][col])
                    if (!ob) continue;
                    else ob--;
                if (row == grid.size() - 1 && col == grid[row].size() - 1)
                    return steps;
                q.push({ row - 1, col, ob });
                q.push({ row, col + 1, ob });
                q.push({ row + 1, col, ob });
                q.push({ row, col - 1, ob });
            }
            steps++;
        }
        return -1;
    }
};