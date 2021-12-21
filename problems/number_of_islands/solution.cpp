class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    count++;
                    remove(grid, row, col);
                }
            }
        }
        return count;
    }
    void remove(std::vector<std::vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size()) return;
        if (col < 0 || col >= grid[row].size()) return;
        if (grid[row][col] != '1') return;
        grid[row][col] = '0';
        remove(grid, row - 1, col);
        remove(grid, row, col + 1);
        remove(grid, row + 1, col);
        remove(grid, row, col - 1);
    }
};