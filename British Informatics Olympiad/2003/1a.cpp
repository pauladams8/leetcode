#include <bits/stdc++.h>

using namespace std;

int main() {
    string isbn;
    cin >> isbn;
    int sum = 0;
    int missing;
    for (int i = 0; i < 10; i++)
        if (isbn[i] == '?')
            missing = i;
        else if (isbn[i] == 'X')
            sum += (10 - i) * 10;
        else
            sum += (10 - i) * (isbn[i] - '0');
    for (int i = 0; i < 10; i++) {
        if ((sum + (10 - missing) * i) % 11 == 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}