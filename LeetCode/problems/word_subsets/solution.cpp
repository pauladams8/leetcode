class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mustContain(26);
        vector<string> universal;
        universal.reserve(words1.size());
        for (string& word : words2) {
            vector<int> contains(26);
            for (char c : word)
                contains[c - 'a']++;
            for (int i = 0; i < 26; i++)
                mustContain[i] = max(mustContain[i], contains[i]);
        }
        for (string& word : words1) {
            vector<int> contains(26);
            for (char c : word)
                contains[c - 'a']++;
            if (isUniversal(contains, mustContain))
                universal.push_back(word);
        }
        return universal;
    }
private:
    bool isUniversal(vector<int>& contains, vector<int>& mustContain) {
        for (int i = 0; i < 26; i++)
            if (contains[i] < mustContain[i])
                return false;
        return true;
    }
};