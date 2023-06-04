class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j])
                    adj[i].push_back(j);
        vector<bool> seen(n);
        for (int i = 0; i < n; i++)
            ans += dfs(adj, i, seen);
        return ans;
    }
private:
    bool dfs(vector<vector<int>>& adj, int i, vector<bool>& seen) {
        if (seen[i])
            return false;
        seen[i] = true;
        for (int j : adj[i])
            dfs(adj, j, seen);
        return true;
    }
};