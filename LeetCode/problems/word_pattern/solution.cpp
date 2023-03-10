class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        stringstream ss(s);
        vector<string> words(26);
        unordered_map<string, char> chars;
        for (char c : pattern) {
            ss >> word;
            if (!ss)
                return false;
            if (words[c - 'a'].size() && word != words[c - 'a'])
                return false;
            if (chars[word] && c != chars[word])
                return false;
            chars[word] = c;
            words[c - 'a'] = word;
        }
        if (ss >> word)
            return false;
        return true;
    }
};