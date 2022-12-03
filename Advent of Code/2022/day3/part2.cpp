#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int sum = 0;
    while (cin) {
        unordered_set<char> prev;
        for (int i = 0; i < 3; i++) {
            unordered_set<char> seen;
            string rucksack;
            cin >> rucksack;
            for (char item : rucksack)
                if (prev.empty() || prev.find(item) != prev.end())
                    seen.insert(item);
            prev = move(seen);
        }
        if (prev.empty()) break;
        char common = *prev.begin();
        if (common >= 'a' && common <= 'z')
            sum += common - 'a' + 1;
        else if (common >= 'A' && common <= 'Z')
            sum += common - 'A' + 27;
    }
    cout << sum << '\n';
}
