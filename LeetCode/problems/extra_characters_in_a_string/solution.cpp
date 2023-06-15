class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> words;
        for (string& word : dictionary)
            words.insert(word);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
            dp[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                dp[i + 1] = min(dp[i + 1], dp[j] + (words.find(s.substr(j, i - j + 1)) == words.end()) * (i - j + 1));
        return dp[n];
    }
};