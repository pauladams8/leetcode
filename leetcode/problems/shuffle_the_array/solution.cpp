class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        for (int i = 0; i < n; i++)
            ans[i * 2] = nums[i], ans[i * 2 + 1] = nums[i + n];
        return ans;
    }
};