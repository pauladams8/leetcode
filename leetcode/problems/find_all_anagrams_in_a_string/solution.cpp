class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sFreq(26), pFreq(26), ans;
        for (char c : p)
            pFreq[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (i >= p.size())
                sFreq[s[i - p.size()] - 'a']--;
            sFreq[s[i] - 'a']++;
            if (i + 1 >= p.size() && sFreq == pFreq)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};