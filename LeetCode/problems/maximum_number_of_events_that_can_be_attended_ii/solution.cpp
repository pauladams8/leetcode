class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<unordered_map<int, int>> dp(k + 1);
        sort(events.begin(), events.end());
        return maxValue(events, k, 0, dp);
    }
private:
    int maxValue(vector<vector<int>>& events, int k, int prev, vector<unordered_map<int, int>>& dp) {
        if (!k)
            return 0;
        if (dp[k][prev])
            return dp[k][prev];
        int n = events.size(), start = upper_bound(events.begin(), events.end(), vector<int>{ prev, INT_MAX, INT_MAX }) - events.begin(), ans = 0;
        for (int i = start; i < n; i++)
            ans = max(ans, maxValue(events, k - 1, events[i][1], dp) + events[i][2]);
        return dp[k][prev] = ans;
    }
};