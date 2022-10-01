class Solution {
public:
    int numDecodings(string s) {
        vector<int> cache(s.size(), -1);
        return numDecodings(s, 0, cache);
    }
private:
    int numDecodings(string& s, int start, vector<int>& cache) {
        if (start >= s.size())
            return 1;
        if (s[start] == '0')
            return 0;
        if (cache[start] != -1)
            return cache[start];
        cache[start] = 0;
        for (int i = start, n = 0; i < s.size(); i++) {
            n = n * 10 + s[i] - '0';
            if (n > 26) break;
            cache[start] += numDecodings(s, i + 1, cache);
        }
        return cache[start];
    }
};