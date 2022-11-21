class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size());
        dp[0] = true;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!dp[i]) continue;
            for (int j = start; j <= nums[i] && i + j < nums.size(); j++)
                dp[i + j] = true;
            start = max(start, nums[i]) - 1;
        }
        return dp[nums.size() - 1];
    }
};