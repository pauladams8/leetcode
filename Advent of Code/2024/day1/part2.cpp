#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n1, n2;
  vector<int> list1;
  unordered_multiset<int> list2;
  while (cin >> n1 >> n2) {
    list1.push_back(n1);
    list2.insert(n2);
  }
  int ans = 0;
  for (int n : list1) {
    ans += n * list2.count(n);
  }
  cout << ans << "\n";
}