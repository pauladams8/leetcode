class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n), fact(n, 1);
        for (int i = 0; i < n; i++)
            nums[i] = i + 1;
        for (int i = 1; i < n; i++)
            fact[i] = i * fact[i - 1];
        k--;
        string ans;
        for (int i = 1; i <= n; i++) {
            int perms = fact[n - i], index = k / perms;
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= perms;
        }
        return ans;
    }
};