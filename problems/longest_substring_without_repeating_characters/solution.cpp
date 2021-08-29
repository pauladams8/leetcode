class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), max = 0;
        unordered_map<char, int> map;
        for (int i = 0, j = 0; i < n; i++) {
            try {
                int ex = map.at(s[i]) + 1;
                if (ex > j)
                    j = ex;
            } catch (out_of_range& e) {}
            map[s[i]] = i;
            int length = (i - j) + 1;
            if (length > max)
                max = length;
        }
        return max;
    }
};