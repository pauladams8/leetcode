#include <bits/stdc++.h>

using namespace std;

void solve() {
    int C = INT_MAX, M = INT_MAX, Y = INT_MAX, K = INT_MAX;
    for (int i = 0; i < 3; i++) {
        int c, m, y, k;
        cin >> c >> m >> y >> k;
        C = min(C, c);
        M = min(M, m);
        Y = min(Y, y);
        K = min(K, k);
    }
    for (int c = max(1000000 - M - Y - K, 0); c <= C; c++) {
        for (int m = max(1000000 - Y - K - c, 0); m <= M; m++) {
            for (int y = max(1000000 - c - m - K, 0); y <= Y; y++) {
                cout << c << ' ' << m << ' ' << y << ' ' << 1000000 - c - m - y << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}