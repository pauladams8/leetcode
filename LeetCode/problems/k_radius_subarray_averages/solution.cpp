class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size(), sum = 0;
        vector<int> avgs(n, -1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= 2 * k) {
                avgs[i - k] = sum / (2 * k + 1);
                sum -= nums[i - 2 * k];
            }
        }
        return avgs;
    }
};