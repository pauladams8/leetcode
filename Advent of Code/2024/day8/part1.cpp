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
  for (auto& positions : antennas) {
    int cnt = positions.size();
    for (int i = 0; i < cnt; i++) {
      for (int j = i + 1; j < cnt; j++) {
        int pos1 = positions[i], pos2 = positions[j], i1 = pos1 / n,
            j1 = pos1 % n, i2 = pos2 / n, j2 = pos2 % n, a1i = 2 * i1 - i2,
            a1j = 2 * j1 - j2, a2i = 2 * i2 - i1, a2j = 2 * j2 - j1;
        if (0 <= a1i && a1i < m && 0 <= a1j && a1j < n &&
            grid[a1i][a1j] != '#') {
          grid[a1i][a1j] = '#';
          ans++;
        }
        if (0 <= a2i && a2i < m && 0 <= a2j && a2j < n &&
            grid[a2i][a2j] != '#') {
          grid[a2i][a2j] = '#';
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}