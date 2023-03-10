class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.size() <= haystack.size(); i++)
            if (matches(haystack, needle, i))
                return i;
        return -1;
    }
private:
    bool matches(string& haystack, string& needle, int start) {
        for (int i = 0; i < needle.size(); i++)
            if (haystack[start + i] != needle[i])
                return false;
        return true;
    }
};