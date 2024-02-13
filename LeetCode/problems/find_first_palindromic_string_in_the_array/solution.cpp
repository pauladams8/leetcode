class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string& word : words)
            if (isPalindrome(word))
                return word;
        return "";
    }
private:
    bool isPalindrome(string& word) {
        int left = 0, right = word.size() - 1;
        while (left < right)
            if (word[left++] != word[right--])
                return false;
        return true;
    }
};