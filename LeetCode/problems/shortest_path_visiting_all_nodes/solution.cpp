class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), ans = 0;
        queue<pair<int, bitset<13>>> q, q1;
        vector<vector<bool>> seen(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            bitset<13> state;
            state.set(i);
            q.push({ i, state });
            seen[i][state.to_ulong()] = true;
        }
        while (!q.empty()) {
            while (!q.empty()) {
                auto [node, state] = q.front();
                q.pop();
                if (state.count() == n)
                    return ans;
                for (auto next : graph[node]) {
                    auto next_state(state);
                    next_state.set(next);
                    if (seen[next][next_state.to_ulong()])
                        continue;
                    q1.push({ next, next_state });
                    seen[next][next_state.to_ulong()] = true;
                }
            }
            ans++;
            swap(q, q1);
        }
        return -1;
    }
};