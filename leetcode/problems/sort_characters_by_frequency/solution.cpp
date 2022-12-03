class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        vector<vector<char>> sorted(s.size() + 1);
        for (auto [c, count] : freq)
            sorted[count].push_back(c);
        for (int count = s.size(), i = 0; count >= 1; count--)
            for (char c : sorted[count])
                for (int j = 0; j < count; j++)
                    s[i++] = c;
        return s;
    }
};