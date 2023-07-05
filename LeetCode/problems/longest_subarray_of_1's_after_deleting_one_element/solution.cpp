class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> prefix(n + 1), suffix(n + 1);
        for (int i = 0; i < n; i++)
            if (nums[i])
                prefix[i + 1] = prefix[i] + 1;
        for (int i = n - 1; i >= 0; i--)
            if (nums[i])
                suffix[i] = suffix[i + 1] + 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, prefix[i] + suffix[i + 1]);
        return ans;
    }
};