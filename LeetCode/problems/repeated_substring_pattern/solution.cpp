class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string prefix;
        for (int i = 1; i < n; i++) {
            prefix += s[i - 1];
            if (n % i == 0 && prefix + s == s + prefix) {
                return true;
            }
        }
        return false;
    }
};