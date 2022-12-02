#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    while (cin) {
        int sum = 0;
        string item;
        while (getline(cin, item) && !item.empty())
            sum += stoi(item);
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}
