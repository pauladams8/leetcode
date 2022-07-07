class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> cache(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return isInterleave(s1, s2, s3, 0, 0, cache);
    }
private:
    bool isInterleave(string s1, string s2, string s3, int i1, int i2, vector<vector<int>>& cache) {
        if (i1 + i2 >= s3.size())
            return i1 >= s1.size() && i2 >= s2.size();
        if (cache[i1][i2] != -1)
            return cache[i1][i2] == 1;
        if (i1 < s1.size() && s1[i1] == s3[i1 + i2] && isInterleave(s1, s2, s3, i1 + 1, i2, cache))
            cache[i1][i2] = true;
        else if (i2 < s2.size() && s2[i2] == s3[i1 + i2] && isInterleave(s1, s2, s3, i1, i2 + 1, cache))
            cache[i1][i2] = true;
        else
            cache[i1][i2] = false;
        return cache[i1][i2];
    }
};