class Solution {
public:
    int countSubstrings(string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
            count += countSubstrings(s, i, i) + countSubstrings(s, i, i + 1);
        return count;
    }
private:
    int countSubstrings(string& s, int i, int j) {
        if (i > j) return 0;
        if (i < 0) return 0;
        if (j >= s.size()) return 0;
        if (s[i] != s[j]) return 0;
        return countSubstrings(s, i - 1, j + 1) + 1;
    }
};