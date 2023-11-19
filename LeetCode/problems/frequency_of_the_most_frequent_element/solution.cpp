class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (long long i = 0; i < n; i++) {
            // find smallest j such that nums[i] * (i - j) - (sum[i] - sum[j]) <= k
            long long left = 0, right = i;
            while (left < right) {
                long long mid = (left + right) / 2;
                if (nums[i] * (i - mid) - sum[i] + sum[mid] <= k) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};