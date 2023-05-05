class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), vowels = 0, ans = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (isVowel(s[r]))
                vowels++;
            if (r - l + 1 != k)
                continue;
            ans = max(ans, vowels);
            if (isVowel(s[l++]))
                vowels--;
        }
        return ans;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};