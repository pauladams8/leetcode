class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        for (int i = 0; i < strs[0].size() && equals(strs, i); i++)
            res += strs[0][i];
        return res;
    }
private:
    bool equals(vector<string>& strs, int i) {
        for (int j = 1; j < strs.size(); j++)
            if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                return false;
        return true;
    }
};