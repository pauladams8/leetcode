#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

inline long long concact(long long a, long long b) {
  string a_str = to_string(a), b_str = to_string(b);
  return stoll(a_str + b_str);
}

bool dfs(vector<long long>& nums, long long target, long long acc,
         long long start) {
  if (acc > target) {
    return false;
  }
  if (start >= nums.size()) {
    return acc == target;
  }
  return dfs(nums, target, acc + nums[start], start + 1) ||
         dfs(nums, target, acc * nums[start], start + 1) ||
         dfs(nums, target, concact(acc, nums[start]), start + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ans = 0;
  string line;
  while (getline(cin, line)) {
    auto split = line.find(":");
    auto left = line.substr(0, split), right = line.substr(split + 1);
    long long testValue = stoll(left);
    stringstream ss(right);
    long long n;
    vector<long long> nums;
    while (ss >> n) {
      nums.push_back(n);
    }
    if (dfs(nums, testValue, nums[0], 1)) {
      ans += testValue;
    }
  }
  cout << ans << "\n";
}