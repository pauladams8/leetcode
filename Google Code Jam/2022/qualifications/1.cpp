#include <bits/stdc++.h>

using namespace std;

void solve() {
    int R, C;
    cin >> R >> C;
    if (R) {
        if (C) {
            cout << "..+";
        }
        for (int j = 1; j < C; j++) {
            cout << "-+";
        }
        cout << '\n';
        if (C) {
            cout << "..|";
        }
        for (int j = 1; j < C; j++) {
            cout << ".|";
        }
        cout << '\n';
        if (C) {
            cout << "+";
        }
        for (int j = 0; j < C; j++) {
            cout << "-+";
        }
        cout << '\n';
    }
    for (int i = 1; i < R; i++) {
        if (C) {
            cout << "|";
        }
        for (int j = 0; j < C; j++) {
            cout << ".|";
        }
        cout << '\n';
        if (C) {
            cout << "+";
        }
        for (int j = 0; j < C; j++) {
            cout << "-+";
        }
        cout << '\n';
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }
}