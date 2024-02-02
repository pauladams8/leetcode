class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            if (!ans.empty() && ans.back().size() < 3) {
                if (n - ans.back().front() <= k) {
                    ans.back().push_back(n);
                } else {
                    return {};
                }
            } else {
                ans.push_back({ n });
            }
        }
        return ans;
    }
};