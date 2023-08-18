class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        vector<vector<bool>> adj(n, vector<bool>(n));
        for (auto& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj[edge[0]][edge[1]] = true;
            adj[edge[1]][edge[0]] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = max(ans, degree[i] + degree[j] - adj[i][j]);
        return ans;
    }
};