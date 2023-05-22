class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        auto cmp = [&](int a, int b) {
            return freq[a] < freq[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int n : nums)
            freq[n]++;
        for (auto [n, cnt] : freq)
            pq.push(n);
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
            ans[i] = pq.top(), pq.pop();
        return ans;
    }
};