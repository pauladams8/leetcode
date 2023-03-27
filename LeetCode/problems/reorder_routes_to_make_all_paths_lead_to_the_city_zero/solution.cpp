class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> from(n), to(n);
        for (auto road : connections)
            from[road[0]].push_back(road[1]), to[road[1]].push_back(road[0]);
        return dfs(0, -1, from, to);
    }
    
    int dfs(int start, int prev, vector<vector<int>>& from, vector<vector<int>>& to) {
        int ans = 0;
        for (auto next : to[start])
            if (next != prev)
                ans += dfs(next, start, from, to);
        for (auto next : from[start])
            if (next != prev)
                ans += dfs(next, start, from, to) + 1;
        return ans;
    }
};