class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;
        for (string& word : words)
            freqMap[word]++;
        vector<vector<string>> freq(words.size() + 1);
        for (auto& [word, count] : freqMap)
            freq[count].push_back(word);
        for (vector<string>& same : freq)
            sort(same.begin(), same.end());
        vector<string> res(k);
        for (int i = 0, count = words.size(), j = 0; i < k; i++) {
            while (j >= freq[count].size())
                count--, j = 0;
            res[i] = freq[count][j++];
        }
        return res;
    }
};