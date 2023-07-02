class Solution {
    vector<pair<int, int>> dir = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0, moves = 0;
        pair<int, int> start = {-1, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    start = {i, j};
                } else if (islower(grid[i][j])) {
                    cnt++;
                }
            }
        }
        queue<pair<pair<int, int>, bitset<6>>> q, next;
        vector<vector<unordered_set<bitset<6>>>> seen(m, vector<unordered_set<bitset<6>>>(n));
        q.push({start, bitset<6>()});
        seen[start.first][start.second].insert(bitset<6>());
        while (!q.empty()) {
            while (!q.empty()) {
                auto [cell, keys] = q.front();
                auto [i, j] = cell;
                q.pop();
                if (islower(grid[i][j]))
                    keys.set(grid[i][j] - 'a');
                if (keys.count() == cnt)
                    return moves;
                for (auto [di, dj] : dir) {
                    int ii = i + di, jj = j + dj;
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n || grid[ii][jj] == '#' || seen[ii][jj].find(keys) != seen[ii][jj].end() || isupper(grid[ii][jj]) && !keys[grid[ii][jj] - 'A'])
                        continue;
                    next.push({{ii, jj}, keys});
                    seen[ii][jj].insert(keys);
                }
            }
            moves++;
            swap(q, next);
        }
        return -1;
    }
};