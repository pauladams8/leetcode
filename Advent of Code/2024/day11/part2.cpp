#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long numStones(long long stone, long long turns,
                    unordered_map<string, long long>& dp) {
  if (!turns) {
    return 1;
  }
  auto& ans = dp[to_string(stone) + "," + to_string(turns)];
  if (ans) {
    return ans;
  }
  if (!stone) {
    return ans = numStones(1, turns - 1, dp);
  }
  string str = to_string(stone);
  long long numDigits = str.size();
  if (numDigits % 2) {
    return ans = numStones(stone * 2024, turns - 1, dp);
  }
  return ans = numStones(stoll(str.substr(0, numDigits / 2)), turns - 1, dp) +
               numStones(stoll(str.substr(numDigits / 2)), turns - 1, dp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long stone, ans = 0;
  vector<long long> stones;
  unordered_map<string, long long> dp;
  while (cin >> stone) {
    stones.push_back(stone);
  }
  for (auto stone : stones) {
    ans += numStones(stone, 75, dp);
  }
  cout << ans << "\n";
}