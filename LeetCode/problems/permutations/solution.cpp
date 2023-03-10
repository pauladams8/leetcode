class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> prefix;
        vector<bool> seen(nums.size());
        vector<vector<int>> res;
        permute(nums, prefix, seen, res);
        return res;
    }
private:
    void permute(vector<int>& nums, vector<int>& prefix, vector<bool>& seen, vector<vector<int>>& res) {
        if (prefix.size() == nums.size()) {
            res.push_back(prefix);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (seen[i]) continue;
            prefix.push_back(nums[i]);
            seen[i] = true;
            permute(nums, prefix, seen, res);
            prefix.pop_back();
            seen[i] = false;
        }
    }
};