class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<int, int> numerals = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        for (int i = s.size() - 1; i >= 0; i--)
            if (i + 1 < s.size() && numerals[s[i]] < numerals[s[i + 1]])
                ans -= numerals[s[i]];
            else
                ans += numerals[s[i]];
        return ans;
    }
};