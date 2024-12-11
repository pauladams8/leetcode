#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                 {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string line;
  vector<string> grid;
  while (cin >> line) {
    grid.push_back(line);
  }
  int m = grid.size(), n = grid[0].size(), ans = 0;
  for (int i = 1; i + 1 < m; i++) {
    for (int j = 1; j + 1 < n; j++) {
      string diag1{{grid[i - 1][j - 1], grid[i][j], grid[i + 1][j + 1]}},
          diag2{{grid[i - 1][j + 1], grid[i][j], grid[i + 1][j - 1]}};
      if ((diag1 == "MAS" || diag1 == "SAM") &&
          (diag2 == "MAS" || diag2 == "SAM")) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}