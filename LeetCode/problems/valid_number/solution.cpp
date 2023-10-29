class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), i = 0;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        if (i < n && isdigit(s[i])) {
            while (i < n && isdigit(s[i])) {
                i++;
            }
            if (i < n && s[i] == '.') {
                i++;
            }
            while (i < n && isdigit(s[i])) {
                i++;
            }
        } else if (i < n && s[i] == '.') {
            i++;
            if (i == n || !isdigit(s[i])) {
                return false;
            }
            while (i < n && isdigit(s[i])) {
                i++;
            }
        } else {
            return false;
        }
        if (i < n && tolower(s[i]) == 'e') {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            if (i == n || !isdigit(s[i])) {
                return false;
            }
            while (i < n && isdigit(s[i])) {
                i++;
            }
        }
        return i == n;
    }
};