class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size(), uniq = 0;
        unordered_map<int, int> cnt;
        for (int n : arr) {
            cnt[n]++;
        }
        vector<int> cnt_cnt(n + 1);
        for (auto [n, n_cnt] : cnt) {
            cnt_cnt[n_cnt]++;
        }
        for (int i = 1; i <= min(n, k); i++) {
            int uniq_with_cnt = min(i * cnt_cnt[i], k) / i;
            uniq += uniq_with_cnt;
            k -= uniq_with_cnt * i;
        }
        return cnt.size() - uniq;
    }
};