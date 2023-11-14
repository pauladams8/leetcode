class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<string>> cache(n, {""});
        return dfs(s, 0, words, cache);
    }
private:
    vector<string> dfs(string& s, int start, unordered_set<string>& words, vector<vector<string>>& cache) {
        int n = s.size();
        if (start == n) {
            return {""};
        }
        auto& ans = cache[start];
        if (ans.empty() || !ans.back().empty()) {
            return ans;
        }
        string word;
        ans.pop_back();
        for (int i = start; i < n; i++) {
            word += s[i];
            if (words.find(word) != words.end()) {
                for (auto& suffix : dfs(s, i + 1, words, cache)) {
                    ans.push_back(word + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        return ans;
    }
};