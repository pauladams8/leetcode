#include <string>

class Solution {
public:
    string longestPalindrome(std::string s) {
        int maxBegin = 0, maxEnd = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            auto checkPalindrome = [&](int left, int right) {
                while (left >= 0 && right < n && s[left] == s[right]) {
                    int length = right - left + 1;
                    int maxLength = maxEnd - maxBegin + 1;
                    if (length > maxLength) {
                        maxBegin = left;
                        maxEnd = right;
                    }
                    left--;
                    right++;
                }
            };
            checkPalindrome(i, i + 1);
            checkPalindrome(i - 1, i + 1);
        }
        return s.substr(maxBegin, (maxEnd - maxBegin) + 1);
    }
};
