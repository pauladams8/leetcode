class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string& word : words) {
            vector<char> wordMap(26), patternMap(26);
            if (matches(word, pattern, wordMap, patternMap))
                res.push_back(word);
        }
        return res;
    }
private:
    bool matches(string& word, string& pattern, vector<char>& wordMap, vector<char>& patternMap) {
        for (int i = 0; i < word.size(); i++) {
            if (wordMap[word[i] - 'a'] && pattern[i] != wordMap[word[i] - 'a'])
                return false;
            if (patternMap[pattern[i] - 'a'] && word[i] != patternMap[pattern[i] - 'a'])
                return false;
            wordMap[word[i] - 'a'] = pattern[i];
            patternMap[pattern[i] - 'a'] = word[i];
        }
        return true;
    }
};