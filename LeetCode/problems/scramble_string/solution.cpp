class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<vector<vector<int>>> cache(s1.size(), vector<vector<int>>(s1.size(), vector<int>(s1.size() + 1, -1)));
        return isScramble(s1, s2, 0, 0, s1.size(), cache);
    }
private:
    // determine if s1[i, i + length) is a scramble of s2[j, j + length)
    bool isScramble(string& s1, string& s2, int i, int j, int length, vector<vector<vector<int>>>& cache) {
        if (length == 1) return s1[i] == s2[j];
        auto& ans = cache[i][j][length];
        if (ans != -1) return ans;
        for (int k = i + 1; k < i + length; k++) {
            // split into 2 strings: s1[i..k) of length l1 and s1[k..i+length) of length l2
            int l1 = k - i, l2 = length - l1;
            if (isScramble(s1, s2, i, j, l1, cache) && isScramble(s1, s2, i + l1, j + l1, l2, cache))
                return ans = true;
            else if (isScramble(s1, s2, i, j + l1, l2, cache) && isScramble(s1, s2, i + l2, j, l1, cache))
                return ans = true;
        }
        return ans = false;
    }
};