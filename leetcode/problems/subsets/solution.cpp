class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> prefix;
        prefix.reserve(nums.size());
        vector<vector<int>> res;
        res.reserve(1 << nums.size());
        subsets(nums, 0, prefix, res);
        return res;
    }
private:
    void subsets(vector<int>& nums, int start, vector<int>& prefix, vector<vector<int>>& res) {
        res.push_back(prefix);
        for (int i = start; i < nums.size(); i++) {
            prefix.push_back(nums[i]);
            subsets(nums, i + 1, prefix, res);
            prefix.pop_back();
        }
    }
};