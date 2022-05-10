#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<string> letterCombinations(std::string digits) {
        return letterCombinations(std::digits, 0);
    }
private:
    std::vector<string> letterCombinations(std::string digits, int i) {
        if (i >= digits.size())
            if (digits.size() == 0)
                return {};
            else
                return { "" };
        std::unordered_map<char, string> map = {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };
        std::vector<string> combs;
        for (char c : map[digits[i]])
            for (std::string comb : letterCombinations(digits, i + 1))
                combs.push_back(c + comb);
        return combs;
    }
};
