class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int ans = 0, exp = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-')
                continue;
            if (s[i] - '0' > INT_MAX / exp)
                return 0;
            int digit = (s[i] - '0') * exp;
            if (digit > INT_MAX - ans)
                return 0;
            ans += digit;
            if (i + 1 < s.size())
                exp *= 10;
        }
        if (s.size() && s[0] == '-')
            ans = -ans;
        return ans;
    }
};