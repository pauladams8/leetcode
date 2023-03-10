class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < target; i++)
            for (int n : nums)
                if (i + n <= target && dp[i + n] <= INT_MAX - dp[i])
                    dp[i + n] += dp[i];
        return dp[target];
    }
};