class Solution {
    const int mod = 1e9 + 7;
    int dir[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int move = 1; move <= maxMove; move++) {
            vector<vector<int>> new_dp(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto [di, dj] : dir) {
                        int ii = i + di, jj = j + dj;
                        if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                            new_dp[i][j] = (new_dp[i][j] + dp[ii][jj]) % mod;
                        } else {
                            new_dp[i][j] = (new_dp[i][j] + 1) % mod;
                        }
                    }
                }
            }
            dp = std::move(new_dp);
        }
        return dp[startRow][startColumn];
    }
};