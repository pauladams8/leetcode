class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size())
            return 0;
        if (col < 0 || col >= grid[row].size())
            return 0;
        if (grid[row][col] != 1)
            return 0;
        grid[row][col] = 0;
        vector<pair<int, int>> directions = {
            { -1, 0 },
            { 0, 1 },
            { 1, 0 },
            { 0, -1 }
        };
        int ans = 1;
        for (auto [di, dj] : directions)
            ans += dfs(grid, row + di, col + dj);
        return ans;
    }
};