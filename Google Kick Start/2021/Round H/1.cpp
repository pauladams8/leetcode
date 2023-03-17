#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S, F;
    cin >> S >> F;
    vector<bool> seen(26);
    for (char c : F)
        seen[c - 'a'] = true;
    int min = 0;
    for (char c : S) {
        int left = c - 'a', right = c - 'a';
        for (int i = 0; i < 26; i++) {
            if (seen[left] || seen[right])
                break;
            left = (left + 25) % 26;
            right = (right + 27) % 26;
            min++;
        }
    }
    cout << min << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}