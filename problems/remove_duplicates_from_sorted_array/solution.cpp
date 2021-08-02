class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), d = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) ++d;
            else
                nums[i - d] = nums[i];
        }
        return n - d;
    }
};