class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans, color(n, -1);
        for (int i = 0; i < n; i++)
            if (isSafe(i, graph, color))
                ans.push_back(i);
        return ans;
    }
private:
    bool isSafe(int i, vector<vector<int>>& adj, vector<int>& color) {
        if (color[i] != -1) return color[i];
        color[i] = 0;
        for (auto kid : adj[i])
            if (!isSafe(kid, adj, color))
                return false;
        color[i] = 1;
        return true;
    }
};