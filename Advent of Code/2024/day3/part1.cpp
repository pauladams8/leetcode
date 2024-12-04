#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 0;
    string memory((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    regex mul("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    auto begin = sregex_iterator(memory.begin(), memory.end(), mul);
    auto end = sregex_iterator();
    for (auto it = begin; it != end; it++) {
        smatch match = *it;
        int num1 = stoi(match[1].str());
        int num2 = stoi(match[2].str());
        ans += num1 * num2;
    }
    cout << ans << "\n";
}