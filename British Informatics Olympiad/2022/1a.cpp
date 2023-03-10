#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 1; i--) {
        s[i] -= s[i - 1] - 'A' + 1;
        if (s[i] < 'A') s[i] += 26;
    }
    cout << s << '\n';
}
