class Solution {
public:
    bool detectCapitalUse(string word) {
        bool lower = false, upper = false;
        for (int i = 1; i < word.size(); i++)
            if (islower(word[i]))
                lower = true;
            else upper = true;
        if (islower(word[0]))
            return !upper;
        return !lower || !upper;
    }
};