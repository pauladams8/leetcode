class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        for (int i =
0; i + k - 1 < s.size(); i++)
            set.insert(s.substr(i, k));
        return hasAllCodes(set, k, "");
    }
private:
    bool hasAllCodes(unordered_set<string>& set, int k, string prefix) {
        if (prefix.size() == k)
            return set.find(prefix) != set.end();
        return hasAllCodes(set, k, prefix + "0") && hasAllCodes(set, k, prefix + "1");
    }
};