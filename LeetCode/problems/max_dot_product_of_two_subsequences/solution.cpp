class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1e6));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = max({
                    dp[i][j + 1],
                    dp[i + 1][j],
                    nums1[i] * nums2[j],
                    dp[i][j] + nums1[i] * nums2[j]
                });
            }
        }
        return dp[m][n];
    }
};