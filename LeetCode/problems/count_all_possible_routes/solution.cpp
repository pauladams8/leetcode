class Solution {
    const int mod = 1e9 + 7;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel, dp);
    }
private:
    int dfs(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp) {
        if (fuel < 0)
            return 0;
        if (dp[start][fuel] != -1)
            return dp[start][fuel];
        int n = locations.size(), ans = start == finish;
        for (int i = 0; i < n; i++)
            if (i != start)
                ans = (ans + dfs(locations, i, finish, fuel - abs(locations[i] - locations[start]), dp)) % mod;
        return dp[start][fuel] = ans;
    }
};