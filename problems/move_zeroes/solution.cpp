class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int n : nums) {
            if (n == 0)
                continue;
            nums[i++] = n;
        }
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};