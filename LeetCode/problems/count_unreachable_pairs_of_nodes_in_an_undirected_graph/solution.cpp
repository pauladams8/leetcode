typedef long long ll;

class Solution {
public:
    ll countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
        ll ans = 0;
        vector<bool> seen(n);
        for (int i = 0; i < n; i++) {
            ll cnt = dfs(i, adj, seen);
            ans += cnt * (n - cnt);
        }
        return ans / 2;
    }
    
    int dfs(int start, vector<vector<int>>& adj, vector<bool>& seen) {
        if (seen[start])
            return 0;
        seen[start] = true;
        int ans = 1;
        for (auto next : adj[start])
            ans += dfs(next, adj, seen);
        return ans;
    }
};