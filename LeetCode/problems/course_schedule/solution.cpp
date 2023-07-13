class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> color(n, -1);
        vector<vector<int>> adj(n);
        for (auto& edge : prerequisites)
            adj[edge[0]].push_back(edge[1]);
        for (int i = 0; i < n; i++)
            if (!canFinish(i, adj, color))
                return false;
        return true;
    }
private:
    bool canFinish(int i, vector<vector<int>>& adj, vector<int>& color) {
        if (color[i] != -1) return color[i];
        color[i] = 0;
        for (auto pre : adj[i])
            if (!canFinish(pre, adj, color))
                return false;
        color[i] = 1;
        return true;
    }
};