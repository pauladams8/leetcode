#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

inline void printGrid(vector<vector<vector<pair<int, int>>>>& grid) {
  int height = grid.size(), width = grid[0].size();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%s",
             grid[i][j].size() ? to_string(grid[i][j].size()).c_str() : ".");
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const long long width = 101, height = 103;
  long long px, py, vx, vy;
  vector<vector<vector<pair<int, int>>>> grid(
      height, vector<vector<pair<int, int>>>(width));
  while (scanf("p=%lld,%lld v=%lld,%lld\n", &px, &py, &vx, &vy) != EOF) {
    grid[py][px].push_back({vx, vy});
  }
  for (long long t = 0; true; t++) {
    if (t % 101 == 29) {
      printGrid(grid);
      printf("t=%lld\n", t);
      this_thread::sleep_until(chrono::system_clock::now() + 0.5s);
    }
    vector<vector<vector<pair<int, int>>>> next(
        height, vector<vector<pair<int, int>>>(width));
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        for (auto [vx, vy] : grid[i][j]) {
          next[((i + vy) % height + height) % height]
              [((j + vx) % width + width) % width]
                  .push_back({vx, vy});
        }
      }
    }
    grid = move(next);
  }
}