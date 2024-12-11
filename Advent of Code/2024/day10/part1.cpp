#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(vector<string>& grid, int i, int j) {
  int m = grid.size(), n = grid[0].size(), ans = grid[i][j] == '9';
  for (auto [di, dj] : dir) {
    int ii = i + di, jj = j + dj;
    if (0 <= ii && ii < m && 0 <= jj && jj < n &&
        grid[ii][jj] == grid[i][j] + 1) {
      ans += dfs(grid, ii, jj);
    }
  }
  grid[i][j] = '.';
  return ans;
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
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '0') {
        vector<string> copy(grid);
        ans += dfs(copy, i, j);
      }
    }
  }
  cout << ans << "\n";
}