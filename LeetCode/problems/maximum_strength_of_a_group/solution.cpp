class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long n = nums.size(), ans = 1, found = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < n && nums[i] < 0 && nums[i + 1] < 0; i += 2)
            ans *= nums[i] * nums[i + 1], found = 1;
        for (int i = n - 1; i >= 0 && nums[i] > 0; i--)
            ans *= nums[i], found = 1;
        return found ? ans : nums.back();
    }
};