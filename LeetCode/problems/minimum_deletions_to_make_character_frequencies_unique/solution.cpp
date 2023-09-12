class Solution {
public:
    int minDeletions(string s) {
        int n = s.size(), ans = 0;
        vector<int> freq(26);
        for (char c : s)
            freq[c - 'a']++;
        vector<int> freqFreq(n + 1);
        for (int cnt : freq)
            freqFreq[cnt]++;
        for (int i = n; i >= 1; i--)
            if (freqFreq[i] > 1)
                freqFreq[i - 1] += freqFreq[i] - 1, ans += freqFreq[i] - 1;
        return ans;
    }
};