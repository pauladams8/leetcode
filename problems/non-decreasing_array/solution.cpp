class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] >= nums[i])
                continue;
            if (modified)
                return false;
            if (i - 1 < 0 || nums[i + 1] >= nums[i - 1])
                nums[i] = nums[i + 1];
            else
                nums[i + 1] = nums[i];
            modified = true;
        }
        return true;
    }
};