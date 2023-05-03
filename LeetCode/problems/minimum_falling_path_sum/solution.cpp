class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
        for (int j = 0; j < n; j++)
            dp[0][j + 1] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i + 1][j + 1] = min({ dp[i][j], dp[i][j + 1], dp[i][j + 2] }) + matrix[i][j];
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[n][j + 1]);
        return ans;
    }
};