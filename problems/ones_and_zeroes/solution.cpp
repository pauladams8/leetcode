class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> count(strs.size(), vector<int>(2));
        for (int i = 0; i < strs.size(); i++)
            for (char c : strs[i])
                count[i][c - '0']++;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (vector<int>& str : count)
            for (int i = m; i >= str[0]; i--)
                for (int j = n; j >= str[1]; j--)
                    dp[i][j] = max(dp[i][j], dp[i - str[0]][j - str[1]] + 1);
        return dp[m][n];
    }
};