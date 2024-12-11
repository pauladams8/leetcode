#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long stone;
  queue<long long> stones, next;
  while (cin >> stone) {
    stones.push(stone);
  }
  for (long long i = 0; i < 25; i++) {
    while (!stones.empty()) {
      auto stone = stones.front();
      stones.pop();
      string str = to_string(stone);
      long long numDigits = str.size();
      if (!stone) {
        next.push(1);
      } else if (numDigits % 2 == 0) {
        next.push(stoll(str.substr(0, numDigits / 2)));
        next.push(stoll(str.substr(numDigits / 2)));
      } else {
        next.push(stone * 2024);
      }
    }
    swap(stones, next);
  }
  cout << stones.size() << "\n";
}