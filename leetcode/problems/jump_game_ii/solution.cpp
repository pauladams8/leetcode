class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[dp.size() - 1] = 0;
        for (int i = dp.size() - 2; i >= 0; i--)
            for (int jump = 1; jump <= nums[i] && i + jump < dp.size(); jump++)
                if (dp[i + jump] != INT_MAX)
                    dp[i] = min(dp[i], dp[i + jump] + 1);
        return dp[0];
    }
};