#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

inline bool isValid(unordered_map<int, int>& idx, unordered_map<int, vector<int>>& rules) {
    for (auto [n, n_idx] : idx) {
        if (!rules.contains(n)) {
            continue;
        }
        for (auto dep : rules[n]) {
            if (idx.contains(dep) && idx[dep] < n_idx) {
                return false;
            }
        }
    }
    return true;
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
        int first = stoi(line.substr(0, split)), second = stoi(line.substr(split+1));
        rules[first].push_back(second);
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
            ans += update[update.size() / 2];
        }
    }
    cout << ans << "\n";
}