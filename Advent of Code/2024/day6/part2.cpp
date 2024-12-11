#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr static int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
constexpr static array<int, 3> OFF_GRID = {-1, -1, -1};

inline pair<int, int> prepareGrid(vector<string>& grid) {
  int m = grid.size(), n = grid[0].size();
  pair<int, int> ans;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '.') {
        grid[i][j] = 0;
      }
      if (grid[i][j] == '^') {
        grid[i][j] = 16;
        ans = {i, j};
      }
    }
  }
  return ans;
}

inline bool hasCycle(vector<string> grid, int i, int j, int d) {
  int m = grid.size(), n = grid[0].size();
  auto [di, dj] = dir[d];
  grid[i + di][j + dj] = '#';
  while (!(grid[i][j] & (1 << d))) {
    grid[i][j] |= 1 << d;
    for (int k = 0; k < 4; k++) {
      int dd = (d + k) % 4;
      auto [di, dj] = dir[dd];
      int ii = i + di, jj = j + dj;
      if (!(0 <= ii && ii < m && 0 <= jj && jj < n)) {
        return false;
      }
      if (grid[ii][jj] != '#') {
        i = ii, j = jj, d = dd;
        break;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string row;
  vector<string> grid;
  while (getline(cin, row)) {
    grid.push_back(row);
  }
  int m = grid.size(), n = grid[0].size(), d = 0, ans = 0;
  auto [i, j] = prepareGrid(grid);
  while (!(grid[i][j] & (1 << d))) {
    grid[i][j] |= 1 << d;
    for (int k = 0; k < 4; k++) {
      int dd = (d + k) % 4;
      auto [di, dj] = dir[dd];
      int ii = i + di, jj = j + dj;
      if (!(0 <= ii && ii < m && 0 <= jj && jj < n)) {
        break;
      }
      if (grid[ii][jj] < 20) {
        if (hasCycle(grid, i, j, dd)) {
          ans++;
          grid[ii][jj] |= (1 << 4);
        }
      }
      if (grid[ii][jj] != '#') {
        i = ii, j = jj, d = dd;
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] & (1 << 4)) {
        cout << "X";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
  cout << ans << "\n";
}