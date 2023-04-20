class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = 0; i < n; i++)
            dp[i][1] = 1;
        for (int l = 2; l <= n; l++)
            for (int i = 0; i + l <= n; i++)
                if (s[i] == s[i + l - 1])
                    dp[i][l] = dp[i + 1][l - 2] + 2;
                else dp[i][l] = max(dp[i + 1][l - 1], dp[i][l - 1]);
        return dp[0][n];
    }
};