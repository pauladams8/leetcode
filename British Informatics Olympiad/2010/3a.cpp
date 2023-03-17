#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int solve() {
    int j, n;
    cin >> j >> n;
    vector<int> caps(j);
    for (int i = 0; i < j; i++)
        cin >> caps[i];
    queue<vector<int>> q;
    queue<vector<int>> next;
    set<vector<int>> seen;
    vector<int> jugs(caps.size(), 0);
    q.push(jugs);
    int steps = 0;
    while (!q.empty()) {
        int stepSize = q.size();
        while (!q.empty()) {
            jugs = q.front();
            q.pop();
            if (seen.find(jugs) != seen.end()) continue;
            seen.insert(jugs);
            for (int i = 0; i < jugs.size(); i++) {
                if (jugs[i] == n) return steps;
                vector<int> newJugs(jugs);
                newJugs[i] = 0;
                next.push(newJugs);
                newJugs[i] = caps[i];
                next.push(newJugs);
                newJugs[i] = jugs[i];
                for (int j = 0; j < jugs.size(); j++) {
                    if (j == i) continue;
                    int amount = min(caps[j] - jugs[j], jugs[i]);
                    newJugs[i] -= amount;
                    newJugs[j] += amount;
                    if (newJugs[i] == jugs[i] && newJugs[j] == jugs[j]) continue;
                    next.push(newJugs);
                    newJugs[i] = jugs[i];
                    newJugs[j] = jugs[j];
                }
            }
        }
        swap(q, next);
        steps++;
    }
    return -1;
}

int main() {
    for (int c = 1; true; c++) {
        int s = solve();
        cout << "Case #" << c << ": " << s << '\n';
    }
}