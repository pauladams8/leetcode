class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0, mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (auto x : nums) {
            ans = (ans + cnt[x - rev(x)]++) % mod;
        }
        return ans;
    }
private:
    int rev(int x) {
        int ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};