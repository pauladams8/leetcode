class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> prefix;
        vector<vector<int>> res;
        findSubsequences(nums, 0, prefix, res);
        return res;
    }
private:
    void findSubsequences(vector<int>& nums, int start, vector<int>& prefix, vector<vector<int>>& res) {
        if (prefix.size() >= 2)
            res.push_back(prefix);
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++) {
            if (!prefix.empty() && nums[i] < prefix.back())
                continue;
            if (seen.find(nums[i]) != seen.end())
                continue;
            seen.insert(nums[i]);
            prefix.push_back(nums[i]);
            findSubsequences(nums, i + 1, prefix, res);
            prefix.pop_back();
        }
    }
};