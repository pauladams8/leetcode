class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowels;
        for (int i = 0; i < s.size(); i++)
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
                vowels.push_back(i);
        for (int left = 0, right = vowels.size() - 1; left < right; left++, right--)
            swap(s[vowels[left]], s[vowels[right]]);
        return s;
    }
};