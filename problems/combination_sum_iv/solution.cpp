class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target + 1, -1);
        return combinationSum4(nums, target, cache);
    }
private:
    int combinationSum4(vector<int>& nums, int target, vector<int>& cache) {
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;
        if (cache[target] != -1)
            return cache[target];
        cache[target] = 0;
        for (int n : nums)
            cache[target] += combinationSum4(nums, target - n, cache);
        return cache[target];
    }
};