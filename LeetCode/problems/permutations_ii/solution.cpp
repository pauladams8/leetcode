class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> prefix;
        unordered_set<int> used;
        vector<vector<int>> perms;
        permuteUnique(nums, prefix, used, perms);
        return perms;
    }
private:
    void permuteUnique(vector<int>& nums, vector<int>& prefix, unordered_set<int>& used, vector<vector<int>>& perms) {
        if (prefix.size() == nums.size()) {
            perms.push_back(prefix);
            return;
        }
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (used.find(i) != used.end())
                continue;
            if (seen.find(nums[i]) != seen.end())
                continue;
            prefix.push_back(nums[i]);
            used.insert(i);
            seen.insert(nums[i]);
            permuteUnique(nums, prefix, used, perms);
            prefix.pop_back();
            used.erase(i);
        }
    }
};