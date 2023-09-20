class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (size_t i = 0; i < n; i++)
            if (popcount(i) == k)
                ans += nums[i];
        return ans;
    }
};