class Solution {
public:
    string makeGood(string s) {
        string good;
        for (int i = 0; i < s.size(); i++)
            if (i + 1 < s.size() && abs(s[i] - s[i + 1]) == 'a' - 'A')
                i++;
            else if (good.size() && abs(s[i] - good.back()) == 'a' - 'A')
                good.pop_back();
            else
                good.push_back(s[i]);
        return good;
    }
};