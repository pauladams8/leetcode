class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> res(nums.size());
        int i = 0, j = nums.size() - 1;
        for (int k = res.size() - 1; k >= 0; k--) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k] = nums[i] * nums[i];
                i++;
            }
            else {
                res[k] = nums[j] * nums[j];
                j--;
            }
        }
        return res;
    }
};