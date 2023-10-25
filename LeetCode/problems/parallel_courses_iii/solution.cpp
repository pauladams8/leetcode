class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> req(n);
        for (auto& edge : relations)
            req[edge[1] - 1].push_back(edge[0] - 1);
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, req, time, dp));
        return ans;
    }
private:
    int dfs(int course, vector<vector<int>>& req, vector<int>& time, vector<int>& dp) {
        if (dp[course])
            return dp[course];
        int max_req = 0;
        for (auto pre : req[course])
            max_req = max(max_req, dfs(pre, req, time, dp));
        return dp[course] = max_req + time[course];
    }
};