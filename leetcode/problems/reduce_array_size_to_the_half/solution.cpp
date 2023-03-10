class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        vector<int> freq;
        for (int n : arr)
            freqMap[n]++;
        for (auto [k, v] : freqMap)
            freq.push_back(v);
        sort(freq.begin(), freq.end(), [](int a, int b) {
            return a > b;
        });
        int count = 0, countDistinct = 0, half = arr.size() / 2 + arr.size() % 2;
        while (count < half) {
            count += freq[countDistinct];
            countDistinct++;
        }
        return countDistinct;
    }
};