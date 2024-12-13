#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

pair<int, int> dfs(vector<string>& grid, int i, int j, vector<vector<bool>>& seen) {
    int m = grid.size(), n = grid[0].size(), area = 1, perimeter = 0, plant = grid[i][j];
    seen[i][j] = true;
    for (auto [di, dj] : dir) {
        int ii = i + di, jj = j + dj;
        if (0 <= ii && ii < m && 0 <= jj << jj < n && grid[ii][jj] == plant && !seen[ii][jj]) {
            auto [adjArea, adjPerimeter] = dfs(grid, ii, jj, seen);
            area += adjArea;
            perimeter += adjPerimeter;
        }
        if (grid[ii][jj] != plant) {
            perimeter++;
        }
    }
    return {area, perimeter};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    vector<string> grid;
    while (cin >> line) {
        grid.push_back(line);
    }
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<bool>> seen(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!seen[i][j]) {
                auto [area, perimeter] = dfs(grid, i, j, seen);
                ans += area * perimeter;
            }
        }
    }
    cout << ans << "\n";
}