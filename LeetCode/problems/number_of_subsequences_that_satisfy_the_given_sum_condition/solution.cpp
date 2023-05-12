class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0, mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        vector<int> two(n, 1);
        for (int i = 1; i < n; i++)
            two[i] = (two[i - 1] * 2) % mod;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int cnt = upper_bound(it, nums.end(), target - *it) - it;
            if (!cnt) break;
            ans = (ans + two[cnt - 1]) % mod;
        }
        return ans;
    }
};