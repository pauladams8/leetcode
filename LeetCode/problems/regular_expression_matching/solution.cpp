class Solution {
public:
    bool isMatch(std::string& s, std::string& p) {
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(std::string& s, int sIndex, std::string& p, int pIndex) {
        for (; pIndex < p.size(); pIndex++) {
            if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {
                while (sIndex < s.size() && p[pIndex] == '.' || s[sIndex] == p[pIndex])
                    if (isMatch(s, sIndex++, p, pIndex + 2))
                        return true;
                pIndex++;
            } else if (sIndex < s.size() && p[pIndex] == '.' || s[sIndex] == p[pIndex])
                sIndex++;
            else return false;
        }
        return sIndex == s.size() && pIndex == p.size();
    }
};