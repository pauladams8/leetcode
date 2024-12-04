#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string report;
    int level, ans = 0;
    while (getline(cin, report)) {
        if (report.empty()) {
            continue;
        }
        vector<int> nums;
        stringstream ss(report);
        while (ss >> level) {
            nums.push_back(level);
        }
        if (isSafe(nums.begin(), nums.end())) {
            ans++;
        }
    }
    cout << ans << "\n";
}