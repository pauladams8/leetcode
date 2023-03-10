class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> prefix;
        prefix.reserve(nums.size());
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, prefix, res);
        return res;
    }
private:
    void subsetsWithDup(vector<int>& nums, int start, vector<int>& prefix, vector<vector<int>>& res) {
        res.push_back(prefix);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            prefix.push_back(nums[i]);
            subsetsWithDup(nums, i + 1, prefix, res);
            prefix.pop_back();
        }
    }
};