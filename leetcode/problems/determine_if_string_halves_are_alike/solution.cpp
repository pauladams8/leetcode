class Solution {
public:
    bool halvesAreAlike(string s) {
        return vowelCount(s, 0, s.size() / 2) == vowelCount(s, s.size() / 2, s.size());
    }
private:
    int vowelCount(string& s, int start, int end) {
        int count = 0;
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        for (int i = start; i < end; i++)
            if (vowels.find(tolower(s[i])) != vowels.end())
                count++;
        return count;
    }
};