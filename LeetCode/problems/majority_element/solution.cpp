class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        for (auto [x, cnt] : freq)
            if (cnt > nums.size() / 2)
                return x;
        return -1;
    }
};