#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll I, p, q;
    cin >> I >> p >> q;
    int logI = ceil(log2(I));
    vector<bool> sieve(I + 1, true);
    for (int i = 2; i * i <= I; i++)
        if (sieve[i])
            for (int j = i * i; j <= I; j += i)
                sieve[j] = false;
    queue<int> queue;
    vector<bool> seen(I + 1);
    queue.push(p);
    int min = 0;
    while (!queue.empty()) {
        min++;
        int n = queue.size();
        for (int i = 0; i < n; i++) {
            int cur = queue.front();
            queue.pop();
            if (cur < 0 || cur > I)
                continue;
            if (seen[cur])
                continue;
            if (!sieve[cur])
                continue;
            if (cur == q) {
                cout << min << '\n';
                return 0;
            }
            seen[cur] = true;
            for (int i = 0; i <= logI; i++) {
                queue.push(cur + (1 << i));
                queue.push(cur - (1 << i));
            }
        }
    }
    cout << -1 << '\n';
}