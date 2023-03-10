class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string prefix;
        vector<string> res;
        restoreIpAddresses(s, 0, 0, prefix, res);
        return res;
    }
private:
    void restoreIpAddresses(string& s, int start, int octets, string prefix, vector<string>& res) {
        if (start >= s.size() && octets == 4) {
            prefix.pop_back();
            res.push_back(prefix);
            return;
        }
        if (start >= s.size() || octets == 4) {
            return;
        }
        int octet = 0;
        for (int i = start; i < s.size(); i++) {
            octet = octet * 10 + s[i] - '0';
            if (octet > 255)
                break;
            prefix.push_back(s[i]);
            prefix.push_back('.');
            restoreIpAddresses(s, i + 1, octets + 1, prefix, res);
            prefix.pop_back();
            if (octet == 0)
                break;
        }
    }
};