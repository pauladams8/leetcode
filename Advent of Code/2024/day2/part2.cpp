#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

template <typename It>
inline bool isValidDistance(It begin, It end) {
  for (auto it = begin; it != end && next(it) != end; it++) {
    int diff = abs(*it - *next(it));
    if (!(1 <= diff && diff <= 3)) {
      return false;
    }
  }
  return true;
}

template <typename It>
inline bool isSafe(It begin, It end) {
  return (is_sorted(begin, end, less<int>()) ||
          is_sorted(begin, end, greater<int>())) &&
         isValidDistance(begin, end);
}

inline bool isSafeRemovingOne(list<int>& ll) {
  if (isSafe(ll.begin(), ll.end())) {
    return true;
  }
  for (auto it = ll.begin(); it != ll.end(); it++) {
    ll.erase(it);
    if (isSafe(ll.begin(), ll.end())) {
      return true;
    }
    ll.insert(next(it), *it);
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string report;
  int level, ans = 0;
  while (getline(cin, report)) {
    if (report.empty()) {
      continue;
    }
    list<int> nums;
    stringstream ss(report);
    while (ss >> level) {
      nums.push_back(level);
    }
    if (isSafeRemovingOne(nums)) {
      ans++;
    }
  }
  cout << ans << "\n";
}