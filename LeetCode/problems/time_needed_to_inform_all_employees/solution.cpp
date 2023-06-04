class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            if (i != headID)
                adj[manager[i]].push_back(i);
        return dfs(headID, adj, informTime);
    }
private:
    int dfs(int i, vector<vector<int>>& adj, vector<int>& time) {
        int ans = 0;
        for (int report : adj[i])
            ans = max(ans, dfs(report, adj, time) + time[i]);
        return ans;
    }
};