class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j = n - 1;
        for (int k = n - 1; k >= 0; k--) {
            int left = nums[i] * nums[i], right = nums[j] * nums[j];
            if (left > right) {
                result[k] = left;
                i++;
            } else {
                result[k] = right;
                j--;
            }
        }
        return result;
    }
};