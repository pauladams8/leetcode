class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> cache(multipliers.size(), vector<int>(multipliers.size(), INT_MIN));
        return maximumScore(nums, multipliers, cache, 0, 0, nums.size() - 1);
    }
private:
    int maximumScore(vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& cache, int i, int start, int end) {
        if (i >= multipliers.size())
            return 0;
        int endDistance = nums.size() - 1 - end;
        if (cache[start][endDistance] != INT_MIN)
            return cache[start][endDistance];
        return cache[start][endDistance] = max(maximumScore(nums, multipliers, cache, i + 1, start + 1, end) + nums[start] * multipliers[i], maximumScore(nums, multipliers, cache, i + 1, start, end - 1) + nums[end] * multipliers[i]);
    }
};