class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (int i = 0; i < s.size(); i++)
            if (i + 1 < s.size() && s[i] == s[i + 1])
                i++;
            else if (!res.empty() && s[i] == res.back())
                res.pop_back();
            else
res.push_back(s[i]);
        return res;
    }
};