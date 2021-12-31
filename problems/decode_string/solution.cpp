class Solution {
public:
    std::string decodeString(std::string& s) {
        int i = 0;
        return decodeString(s, i);
    }
private:
    std::string decodeString(std::string& s, int& i) {
        std::string result;
        int k = 0;
        for (; i < s.size() && s[i] != ']'; i++) {
            if (s[i] == '[') {
                i++;
                std::string decoded = decodeString(s, i);
                for (; k > 0; k--) result += decoded;
            } else if (s[i] - '0' >= 0 && s[i] - '0' <= 9) k = k * 10 + (s[i] - '0');
            else result += s[i];
        }
        return result;
    }
};