class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), s = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (s > 0)
                nums[i - s] = nums[i];
            if (seen.find(nums[i]) != seen.end())
                ++s;
            seen.insert(nums[i]);
        }
        return n - s;
    }
};