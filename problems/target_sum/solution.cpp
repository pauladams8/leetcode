class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        std::vector<std::unordered_map<int, int>> cache(nums.size());
        return findTargetSumWays(nums, target, 0, cache);
    }
private:
    int findTargetSumWays(std::vector<int>& nums, int target, int i, std::vector<std::unordered_map<int, int>>& cache) {
        if (i >= nums.size())
            return target == 0 ? 1 : 0;
        if (cache[i].find(target) == cache[i].end())
            cache[i][target] = findTargetSumWays(nums, target + nums[i], i + 1, cache) + findTargetSumWays(nums, target - nums[i], i + 1, cache);
        return cache[i][target];
    }
};