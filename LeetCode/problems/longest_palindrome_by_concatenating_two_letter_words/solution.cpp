class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> freq;
        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (freq[rev])
                ans += 4, freq[rev]--;
            else
                freq[word]++;
        }
        bool found = false;
        for (int i = 0; i < words.size() && !found; i++)
            if (words[i][0] == words[i][1] && freq[words[i]])
                ans += 2, found = true;
        return ans;
    }
};