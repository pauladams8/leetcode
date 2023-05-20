class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> seen(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components = -1, redundant = 0;
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                components++;
                redundant += dfs(i, adj, seen);
            }
        }
        cout << redundant << " " << components << "\n";
        return redundant < components ? -1 : components;
    }
private:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& seen) {
        int ans = 0;
        seen[u] = -1;
        for (auto v : adj[u]) {
            if (!seen[v])
                ans += dfs(v, adj, seen);
            else if (seen[v] > 0) ans++;
        }
        seen[u] = 1;
        return ans;
    }
};