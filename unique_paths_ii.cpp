#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        return uniquePathsWithObstacles(obstacleGrid, paths, 0, 0);
    }
private:
    int uniquePathsWithObstacles(vector<vector<int>>& grid, vector<vector<int>>& paths, int i, int j) {
        if (i < 0 || i >= grid.size())
            return 0;
        if (j < 0 || j >= grid[i].size())
            return 0;
        if (grid[i][j] != 0)
            return 0;
        if (i == grid.size() - 1 && j == grid[i].size() - 1)
            return 1;
        if (paths[i][j])
            return paths[i][j];
        paths[i][j] = uniquePathsWithObstacles(grid, paths, i + 1, j) + uniquePathsWithObstacles(grid, paths, i, j + 1);
        return paths[i][j];
    }
};
