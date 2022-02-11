#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;
        const int period = 2 * numRows - 2;
        std::string res;
        for (int row = 0; row < numRows; row++)
            for (int i = row; i < s.size(); i += period - 2 * (i % (numRows - 1)))
                res += s[i];
        return res;
    }
};
