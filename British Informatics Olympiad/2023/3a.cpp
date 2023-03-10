#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    vector<int> start(4), end(4);
    for (int i = 0; i < 4; i++)
        cin >> start[i];
    for (int i = 0; i < 4; i++)
        cin >> end[i];
    queue<vector<int>> q;
    set<vector<int>> seen;
    q.push(start);
    seen.insert(start);
    int moves = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            vector<int> state = q.front();
            q.pop();
            if (state == end) {
                cout << moves << '\n';
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                if (!state[i])
                    continue;
                for (int j = 0; j < 4; j++) {
                    vector<int> newState(state);
                    newState[j] = newState[j] * 10 + newState[i] % 10;
                    newState[i] /= 10;
                    if (seen.find(newState) != seen.end())
                        continue;
                    q.push(newState);
                    seen.insert(newState);
                }
            }
        }
        moves++;
    }
    cout << -1 << '\n';
}
