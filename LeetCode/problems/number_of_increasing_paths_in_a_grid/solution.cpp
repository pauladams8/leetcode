class Solution {
    const int mod = 1e9 + 7;
    vector<pair<int, int>> dir = {
        { -1, 0 },
        { 0, 1 },
        { 1, 0 },
        { 0, -1 }
    };
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = (ans + dfs(grid, i, j, dp)) % mod;
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size(), ans = 1;
        if (dp[i][j])
            return dp[i][j];
        for (auto [di, dj] : dir) {
            int ii = i + di, jj = j + dj;
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] > grid[i][j])
                ans = (ans + dfs(grid, ii, jj, dp)) % mod;
        }
        return dp[i][j] = ans;
    }
};