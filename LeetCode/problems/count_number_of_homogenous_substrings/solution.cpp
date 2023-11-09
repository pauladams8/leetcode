class Solution {
    const int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int n = s.size(), ans = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1])
                dp[i] = (dp[i] + dp[i - 1]) % mod;
        for (int i = 0; i < n; i++)
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};