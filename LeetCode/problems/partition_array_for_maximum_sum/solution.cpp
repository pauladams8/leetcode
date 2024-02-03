class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            int part_max = 0;
            for (int j = i; j >= 0 && i - j < k; j--) {
                part_max = max(part_max, arr[j]);
                dp[i + 1] = max(dp[i + 1], part_max * (i - j + 1) + dp[j]);
            }
        }
        return dp[n];
    }
};