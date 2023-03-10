class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations(digits, 0);
    }
private:
    vector<string> letterCombinations(string digits, int i) {
        if (i >= digits.size())
            if (digits.size() == 0)
                return {};
            else
                return { "" };
        unordered_map<char, string> map = {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };
        vector<string> combs;
        for (char c : map[digits[i]])
            for (string comb : letterCombinations(digits, i + 1))
                combs.push_back(c + comb);
        return combs;
    }
};