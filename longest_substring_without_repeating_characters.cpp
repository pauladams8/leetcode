#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> seen;
        int start = 0, max = 0;
        for (int end = 0; end < s.size(); end++) {
            auto it = seen.find(s[end]);
            if (it != seen.end() && it->second >= start)
                start = it->second + 1;
            seen[s[end]] = end;
            max = std::max(max, end - start + 1);
        }
        return max;
    }
};
