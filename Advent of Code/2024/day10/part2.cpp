#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(vector<string>& grid, int i, int j, vector<vector<int>>& dp) {
  int m = grid.size(), n = grid[0].size();
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  dp[i][j] = grid[i][j] == '9';
  for (auto [di, dj] : dir) {
    int ii = i + di, jj = j + dj;
    if (0 <= ii && ii < m && 0 <= jj && jj < n &&
        grid[ii][jj] == grid[i][j] + 1) {
      dp[i][j] += dfs(grid, ii, jj, dp);
    }
  }
  return dp[i][j];
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
  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '0') {
        ans += dfs(grid, i, j, dp);
      }
    }
  }
  cout << ans << "\n";
}