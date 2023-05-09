typedef long long ll;

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n);
        for (int i = n - 1; i >= 0; i--)
            dp[i] = max(i + 1 < n ? dp[i + 1] : 0, questions[i][0] + (i + questions[i][1] + 1 < n ? dp[i + questions[i][1] + 1] : 0));
        return dp[0];
    }
};