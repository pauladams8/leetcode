class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        while (i1 < word1.size() && i2 < word2.size()) {
            for (; j1 < word1[i1].size() && j2 < word2[i2].size(); j1++, j2++)
                if (word1[i1][j1] != word2[i2][j2])
                    return false;
            if (i1 < word1.size() && j1 >= word1[i1].size())
                i1++, j1 = 0;
            if (i2 < word2.size() && j2 >= word2[i2].size())
                i2++, j2 = 0;
        }
        return i1 >= word1.size() && i2 >= word2.size();
    }
};