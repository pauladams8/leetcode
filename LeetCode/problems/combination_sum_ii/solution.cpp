class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> prefix;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        combinationSum2(nums, target, 0, prefix, res);
        return res;
    }
private:
    void combinationSum2(vector<int>& nums, int target, int start, vector<int>& prefix, vector<vector<int>>& res) {
        if (target == 0)
            res.push_back(prefix);
        if (target <= 0)
            return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            prefix.push_back(nums[i]);
            combinationSum2(nums, target - nums[i], i + 1, prefix, res);
            prefix.pop_back();
        }
    }
};