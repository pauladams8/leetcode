#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

inline pair<int, int> prepareGrid(vector<string>& grid) {
  int m = grid.size(), n = grid[0].size();
  pair<int, int> guard;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '^') {
        guard = {i, j};
      }
      if (grid[i][j] != '#') {
        grid[i][j] = 0;
      }
    }
  }
  return guard;
}

inline int countPositions(vector<string>& grid) {
  int m = grid.size(), n = grid[0].size(), d = 0, ans = 0;
  auto [i, j] = prepareGrid(grid);
  while (!(grid[i][j] & (1 << d))) {
    ans += !grid[i][j];
    grid[i][j] |= 1 << d;
    for (int k = 0; k < 4; k++) {
      int dd = (d + k) % 4;
      auto [di, dj] = dir[dd];
      int ii = i + di, jj = j + dj;
      if (!(0 <= ii && ii < m && 0 <= jj && jj < n)) {
        return ans;
      }
      if (grid[ii][jj] != '#') {
        i = ii, j = jj, d = dd;
        break;
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string row;
  vector<string> grid;
  while (getline(cin, row)) {
    grid.push_back(row);
  }
  cout << countPositions(grid) << "\n";
}