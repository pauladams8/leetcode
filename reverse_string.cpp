#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            std::swap(s[i++], s[j--]);
    }
};
