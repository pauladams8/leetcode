class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        vector<int> freq1(26), freq2(26);
        for (char c : word1)
            freq1[c - 'a']++;
        for (char c : word2)
            freq2[c - 'a']++;
        vector<int> freq(word1.size() + 1);
        for (int i = 0; i < 26; i++)
            if (!freq1[i] != !freq2[i])
                return false;
            else freq[freq1[i]]++, freq[freq2[i]]--;
        for (int i = 0; i < freq.size(); i++)
            if (freq[i])
                return false;
        return true;
    }
};