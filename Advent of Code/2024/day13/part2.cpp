#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ans = 0;
  while (true) {
    long long ax, ay, bx, by, px, py;
    if (scanf("Button A: X+%lld, Y+%lld\n", &ax, &ay) == EOF) {
      break;
    }
    if (scanf("Button B: X+%lld, Y+%lld\n", &bx, &by) == EOF) {
      break;
    }
    if (scanf("Prize: X=%lld, Y=%lld\n", &px, &py) == EOF) {
      break;
    }
    px += 10000000000000;
    py += 10000000000000;
    long long aNumerator = px * by - bx * py, aDenominator = ax * by - bx * ay,
              bNumerator = ax * py - ay * px, bDenominator = ax * by - ay * bx;
    if (aNumerator % aDenominator == 0 && bNumerator % bDenominator == 0) {
      long long a = aNumerator / aDenominator, b = bNumerator / bDenominator;
      ans += 3 * a + b;
    }
  }
  cout << ans << "\n";
}