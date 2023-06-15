class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + piles[i];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                dp[i][j] = sum[j + 1] - sum[i] - min(dp[i + 1][j], dp[i][j - 1]);
        return dp[0][n - 1] > 0;
    }
};