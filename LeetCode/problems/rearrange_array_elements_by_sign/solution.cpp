class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pos = 0, neg = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i += 2) {
            while (nums[pos] < 0) {
                pos++;
            }
            while (nums[neg] > 0) {
                neg++;
            }
            ans[i] = nums[pos++];
            ans[i + 1] = nums[neg++];
        }
        return ans;
    }
};