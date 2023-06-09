class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, j = n - 1;
        for (int i = 0; i < m; i++) {
            while (j >= 0 && grid[i][j] < 0)
                j--;
            ans += n - j - 1;
        }
        return ans;
    }
};