class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto road : roads)
            adj[road[0]].push_back({ road[1], road[2] }), adj[road[1]].push_back({ road[0], road[2] });
        vector<bool> seen(n + 1);
        return dfs(1, n, adj, seen);
    }
    
    int dfs(int start, int end, vector<vector<pair<int, int>>>& adj, vector<bool>& seen) {
        if (seen[start])
            return INT_MAX;
        seen[start] = true;
        int ans = INT_MAX;
        for (auto [next, dist] : adj[start])
            ans = min({ ans, dist, dfs(next, end, adj, seen) });
        return ans;
    }
};