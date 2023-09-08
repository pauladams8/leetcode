class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict;
        for (string& word : wordDict)
            dict.insert(word);
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i - j + 1)) != dict.end()) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};