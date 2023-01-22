class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> prefix;
        vector<vector<string>> res;
        partition(s, 0, prefix, res);
        return res;
    }
private:
    void partition(string& s, int start, vector<string>& prefix, vector<vector<string>>& res) {
        if (start >= s.size()) {
            for (string& sub : prefix)
                if (!isPalindrome(sub))
                    return;
            res.push_back(prefix);
            return;
        }
        string part;
        part.push_back(s[start]);
        prefix.push_back(part);
        partition(s, start + 1, prefix, res);
        prefix.pop_back();
        if (!prefix.empty()) {
            prefix.back().push_back(s[start]);
            partition(s, start + 1, prefix, res);
            prefix.back().pop_back();
        }
    }
    
    bool isPalindrome(string& s) {
        int left = 0, right = s.size() - 1;
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
};