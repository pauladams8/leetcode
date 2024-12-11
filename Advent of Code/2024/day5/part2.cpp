#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

inline bool isValid(unordered_map<int, int>& idx,
                    unordered_map<int, vector<int>>& rules) {
  for (auto [n, n_idx] : idx) {
    if (!rules.contains(n)) {
      continue;
    }
    for (auto dep : rules[n]) {
      if (idx.contains(dep) && idx[dep] > n_idx) {
        return false;
      }
    }
  }
  return true;
}

inline void tsort(int n, unordered_map<int, vector<int>>& rules,
                  vector<int>& ans, unordered_map<int, bool>& unseen) {
  for (int dep : rules[n]) {
    if (unseen[dep]) {
      tsort(dep, rules, ans, unseen);
    }
  }
  ans.push_back(n);
  unseen[n] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int ans = 0;
  string line;
  unordered_map<int, vector<int>> rules;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    auto split = line.find("|");
    int first = stoi(line.substr(0, split)),
        second = stoi(line.substr(split + 1));
    rules[second].push_back(first);
  }
  while (getline(cin, line)) {
    string page;
    stringstream ss(line);
    vector<int> update;
    while (getline(ss, page, ',')) {
      update.push_back(stoi(page));
    }
    int n = update.size();
    unordered_map<int, int> idx;
    for (int i = 0; i < n; i++) {
      idx[update[i]] = i;
    }
    if (isValid(idx, rules)) {
      continue;
    }
    vector<int> sorted;
    sorted.reserve(n);
    unordered_map<int, bool> unseen;
    for (int n : update) {
      unseen[n] = true;
    }
    for (int n : update) {
      if (unseen[n]) {
        tsort(n, rules, sorted, unseen);
      }
    }
    ans += sorted[n / 2];
  }
  cout << ans << "\n";
}