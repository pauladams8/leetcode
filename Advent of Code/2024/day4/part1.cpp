#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                 {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string line, xmas = "XMAS";
  vector<string> grid;
  while (cin >> line) {
    grid.push_back(line);
  }
  int m = grid.size(), n = grid[0].size(), ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (auto [di, dj] : dir) {
        int ii = i, jj = j, cnt = 0;
        while (0 <= ii && ii < m && 0 <= jj && jj < n && cnt < 4 &&
               grid[ii][jj] == xmas[cnt]) {
          cnt++;
          ii += di;
          jj += dj;
        }
        ans += cnt == 4;
      }
    }
  }
  cout << ans << "\n";
}