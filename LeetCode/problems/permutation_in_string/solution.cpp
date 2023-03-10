class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26), freq2(26);
        for (char c : s1)
            freq1[c - 'a']++;
        for (int i = 0; i < s2.size(); i++) {
            if (i >= s1.size())
                freq2[s2[i - s1.size()] - 'a']--;
            freq2[s2[i] - 'a']++;
            if (i + 1 >= s1.size() && freq1 == freq2)
                return true;
        }
        return false;
    }
};