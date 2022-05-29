#include <set>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<set<string>> dp(n + 1);
        dp[0] = { "" };
        for (int i = 1; i <= n; i++) {
            for (const string& s : dp[i - 1]) {
                dp[i].insert("()" + s);
                dp[i].insert("(" + s + ")");
                dp[i].insert(s + "()");
            }
            for (int j = 2; j < i; j++)
                for (const string& s1: dp[j])
                    for (const string& s2 : dp[i - j])
                        dp[i].insert(s1 + s2);
        }
        return vector(dp[n].begin(), dp[n].end());
    }
};
