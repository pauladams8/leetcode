class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1), res;
        for (int i = 0, count = 0; i < prev.size(); i++) {
            count++;
            if (i + 1 < prev.size() && prev[i] == prev[i + 1])
                continue;
            res += to_string(count) + prev[i];
            count = 0;
        }
        return res;
    }
};