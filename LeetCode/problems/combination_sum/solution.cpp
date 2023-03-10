class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> prefix;
        vector<vector<int>> res;
        combinationSum(candidates, target, 0, prefix, res);
        return res;
    }
private:
    void combinationSum(vector<int>& nums, int target, int start, vector<int>& prefix, vector<vector<int>>& res) {
        if (target == 0)
            res.push_back(prefix);
        if (target <= 0)
            return;
        for (int i = start; i < nums.size(); i++) {
            prefix.push_back(nums[i]);
            combinationSum(nums, target - nums[i], i, prefix, res);
            prefix.pop_back();
        }
    }
};