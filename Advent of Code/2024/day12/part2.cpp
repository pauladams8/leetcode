#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

inline bool isValid(vector<string>& grid, int i, int j) {
  int m = grid.size(), n = grid[0].size();
  return 0 <= i && i < m && 0 <= j && j < n;
}

pair<int, int> dfs(vector<string>& grid, int i, int j,
                   vector<vector<bool>>& seen, vector<string>& grid2) {
  int m = grid.size(), n = grid[0].size(), area = 1, sides = 0;
  seen[i][j] = true;
  auto isPartOfShape = [&](int ii, int jj) -> bool {
    return isValid(grid, ii, jj) && grid[i][j] == grid[ii][jj];
  };
  for (int k = 0; k < 4; k++) {
    auto [di, dj] = dir[k];
    int ii = i + di, jj = j + dj, prev = (k + 3) % 4;
    if (isPartOfShape(ii, jj) && !seen[ii][jj]) {
      auto [adjArea, adjSides] = dfs(grid, ii, jj, seen, grid2);
      area += adjArea;
      sides += adjSides;
    } else if (!isPartOfShape(ii, jj) &&
               (!isPartOfShape(i + dir[prev][0], j + dir[prev][1]) ||
                isPartOfShape(ii + dir[prev][0], jj + dir[prev][1]))) {
        sides++;
        grid2[i][j] = (isdigit(grid2[i][j]) ? grid2[i][j] : '0') + 1;
      }
  }
  return {area, sides};
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
  vector<string> grid2(grid);
  vector<vector<bool>> seen(m, vector<bool>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!seen[i][j]) {
        auto [area, sides] = dfs(grid, i, j, seen, grid2);
        ans += area * sides;
      }
    }
  }
  cout << ans << "\n";
}