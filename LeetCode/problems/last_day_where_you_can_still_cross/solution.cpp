class Solution {
    vector<pair<int, int>> dir = {
        { -1, 0 },
        { 0, 1 },
        { 1, 0 },
        { 0, -1 }
    };
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        vector<vector<int>> water(row, vector<int>(col, INT_MAX));
        for (int i = 0; i < n; i++)
            water[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canCross(water, mid))
                left = mid;
            else right = mid - 1;
        }
        return left;
    }
private:
    bool canCross(vector<vector<int>>& grid, int day) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n));
        for (int i = 0; i < n; i++)
            if (canCross(grid, day, 0, i, seen))
                return true;
        return false;
    }
    
    bool canCross(vector<vector<int>>& grid, int day, int i, int j, vector<vector<bool>>& seen) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j] || day >= grid[i][j])
            return false;
        if (i == m - 1)
            return true;
        seen[i][j] = true;
        for (auto [di, dj] : dir)
            if (canCross(grid, day, i + di, j + dj, seen))
                return true;
        return false;
    }
};