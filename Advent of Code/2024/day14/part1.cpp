#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const long long width = 101, height = 103;
  long long px, py, vx, vy, ans = 1, halfWidth = width / 2,
                            halfHeight = height / 2;
  long long quads[4] = {0};
  while (scanf("p=%lld,%lld v=%lld,%lld\n", &px, &py, &vx, &vy) != EOF) {
    px = ((px + 100 * vx) % width + width) % width;
    py = ((py + 100 * vy) % height + height) % height;
    if ((width % 2 == 0 || px != width / 2) && (height % 2 == 0 || py != height / 2)) {
      quads[2 * (py / (height / 2 + (height % 2))) + px / (width / 2 + (width % 2))]++;
    }
  }
  for (auto quad : quads) {
    ans *= quad;
  }
  cout << ans << "\n";
}