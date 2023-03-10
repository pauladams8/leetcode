class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> seen(n + 1);
        vector<vector<int>> map(n + 1, vector<int>(n + 1, -1));
        for (vector<int>& time : times)
            map[time[0]][time[1]] = time[2];
        dfs(map, seen, k);
        int max = -1;
        for (int i = 1; i <= n; i++)
            if (map[k][i] == -1)
                return -1;
            else
                max = std::max(max, map[k][i]);
        return max;
    }
private:
    void dfs(vector<vector<int>>& times, vector<bool>& seen, int u) {
        if (seen[u]) return;
        seen[u] = true;
        times[u][u] = 0;
        for (int v = 0; v < times[u].size(); v++) {
            if (times[u][v] == -1)
                continue;
            dfs(times, seen, v);
            for (int vv = 0; vv < times[v].size(); vv++) {
                if (times[v][vv] == -1)
                    continue;
                if (times[u][vv] == -1)
                    times[u][vv] = times[u][v] + times[v][vv];
                else
                    times[u][vv] = min(times[u][vv], times[u][v] + times[v][vv]);
            }
        }
    }
};