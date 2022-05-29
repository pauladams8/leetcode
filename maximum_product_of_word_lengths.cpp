#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int msf = 0;
        for (int i = 0; i < words.size(); i++) {
            vector<bool> chars(26);
            for (char c : words[i])
                chars[c - 'a'] = true;
            for (int j = 0; j < words.size(); j++) {
                if (j == i) continue;
                bool ok = true;
                for (char c : words[j]) {
                    if (chars[c - 'a']) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                msf = max(msf, (int) words[i].size() * (int) words[j].size());
            }
        }
        return msf;
    }
};
