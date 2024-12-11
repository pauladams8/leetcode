#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string line;
  vector<string> grid;
  while (cin >> line) {
    grid.push_back(line);
  }
  int m = grid.size(), n = grid[0].size(), ans = 0;
  vector<vector<int>> antennas(128);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] != '.') {
        antennas[grid[i][j]].push_back(i * n + j);
      }
    }
  }
  auto isValid = [&](int i, int j) -> bool {
    return 0 <= i && i < m && 0 <= j && j < n;
  };
  for (auto& positions : antennas) {
    int cnt = positions.size();
    for (int i = 0; i < cnt; i++) {
      for (int j = i + 1; j < cnt; j++) {
        int pos1 = positions[i], pos2 = positions[j], i1 = pos1 / n,
            j1 = pos1 % n, i2 = pos2 / n, j2 = pos2 % n;
        for (int m = 0; isValid(i1 + m * (i1 - i2), j1 + m * (j1 - j2)); m++) {
          int ai = i1 + m * (i1 - i2), aj = j1 + m * (j1 - j2);
          if (grid[ai][aj] != '#') {
            grid[ai][aj] = '#';
            ans++;
          }
        }
        for (int m = 0; isValid(i1 + m * (i1 - i2), j1 + m * (j1 - j2)); m--) {
          int ai = i1 + m * (i1 - i2), aj = j1 + m * (j1 - j2);
          if (grid[ai][aj] != '#') {
            grid[ai][aj] = '#';
            ans++;
          }
        }
      }
    }
  }
  cout << ans << "\n";
}