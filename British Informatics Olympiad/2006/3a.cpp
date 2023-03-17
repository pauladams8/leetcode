#include <bits/stdc++.h>

using namespace std;

int countWays(int s, int d, vector<vector<int>>& cache);

int main() {
    int s, d;
    cin >> s >> d;
    vector<vector<int>> ways(s + 1, vector<int>(d + 1, -1));
    cout << countWays(s, d, ways) << '\n';
}

int countWays(int s, int d, vector<vector<int>>& cache) {
    if (s < 0)
        return 0;
    if (s == 0)
        return d == 0 ? 1 : 0;
    if (d == 0)
        return 0;
    if (cache[s][d] != -1)
        return cache[s][d];
    cache[s][d] = 0;
    for (int i = 1; i <= 20; i++)
        cache[s][d] += countWays(s - (d == 1 ? 2 * i : i), d - 1, cache);
    return cache[s][d];
}