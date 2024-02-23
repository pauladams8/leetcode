class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1), trusted_by(n + 1);
        for (auto& edge : trust) {
            trusts[edge[0]]++;
            trusted_by[edge[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trusts[i] == 0 && trusted_by[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};