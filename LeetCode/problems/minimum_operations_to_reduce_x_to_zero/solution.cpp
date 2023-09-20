class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> sum(n + 1);
        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + nums[i];
        for (int i = 0; i <= n; i++)
            idx[sum[i]] = i;
        for (int i = 0; i < n; i++) {
            int target = sum[n] + sum[i] - x;
            if (idx.find(target) != idx.end() && i <= idx[target])
                ans = min(ans, n - idx[target] + i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};