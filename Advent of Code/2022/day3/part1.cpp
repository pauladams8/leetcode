#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string rucksack;
    int sum = 0;
    while (cin >> rucksack) {
        int half = rucksack.size() / 2;
        unordered_set<char> seen;
        for (int i = 0; i < half; i++)
            seen.insert(rucksack[i]);
        for (int i = half; i < rucksack.size(); i++) {
            if (seen.find(rucksack[i]) != seen.end()) {
                if (rucksack[i] >= 'a' && rucksack[i] <= 'z')
                    sum += rucksack[i] - 'a' + 1;
                else if (rucksack[i] >= 'A' && rucksack[i] <= 'Z')
                    sum += rucksack[i] - 'A' + 27;
                break;
            }
        }
    }
    cout << sum << '\n';
}
