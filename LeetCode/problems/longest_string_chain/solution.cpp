class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto& a, auto& b) {
            return a.size() < b.size();
        });
        int n = words.size(), ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (ans >= n - i)
                break;
            ans = max(ans, dfs(words, i, dp));
        }
        return ans;
    }
private:
    int dfs(vector<string>& words, int start, vector<int>& dp) {
        if (dp[start])
            return dp[start];
        int n = words.size(), ans = 1, next = upper_bound(words.begin() + start + 1, words.end(), words[start], [](auto& prev, auto& word) {
            return word.size() > prev.size();
        }) - words.begin();
        for (int i = next; i < n && words[i].size() == words[start].size() + 1; i++) {
            if (ans > n - i)
                break;
            if (isPredecessor(words[start], words[i]))
                ans = max(ans, dfs(words, i, dp) + 1);
        }
        return dp[start] = ans;
    }
    
    bool isPredecessor(string& a, string& b) {
        int n = a.size(), diff = 0;
        for (int i = 0; i - diff < n; i++) {
            if (a[i - diff] != b[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return true;
    }
};