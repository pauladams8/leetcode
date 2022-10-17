class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> contains(26);
        for (char c : sentence)
            contains[c - 'a'] = true;
        for (int i = 0; i < 26; i++)
            if (!contains[i])
                return false;
        return true;
    }
};