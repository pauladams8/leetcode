class Solution {
    const int mod = 1e9 + 7;
    const vector<vector<int>> states = {
        { 1, 2, 3, 4, 5 },
        { 2 },
        { 1, 3 },
        { 1, 2, 4, 5 },
        { 3, 5 },
        { 1 }
    };
public:
    int countVowelPermutation(int n) {
        vector<int> cnt(6, 1);
        for (int i = 0; i < n; i++) {
            vector<int> cnt1(6);
            for (int j = 0; j < 6; j++) {
                for (auto next : states[j]) {
                    cnt1[j] = (cnt1[j] + cnt[next]) % mod;
                }
            }
            cnt = move(cnt1);
        }
        return cnt[0];
    }
};