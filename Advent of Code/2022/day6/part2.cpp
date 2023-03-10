#include <iostream>
#include <string>
#include <vector>

using namespace std;

int firstUnique4(string& line) {
    vector<int> seen(26, -1);
    for (int start = 0, end = 0; end < line.size(); end++) {
        start = max(start, seen[line[end] - 'a'] + 1);
        if (end - start + 1 == 14)
            return end + 1;
        seen[line[end] - 'a'] = end;
    }
    return INT_MAX;
}

int main() {
    string line;
    while (cin >> line)
        cout << firstUnique4(line) << '\n';
}
