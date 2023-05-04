class Solution {
    vector<pair<int, int>> dir = {
        { -1, 0 },
        { 0, 1 },
        { 1, 0 },
        { 0, -1 }
    };
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j])
            return 0;
        int ans = 0, fish = grid[i][j];
        grid[i][j] = 0;
        for (auto [di, dj] : dir)
            ans += dfs(grid, i + di, j + dj);
        return ans + fish;
    }
};