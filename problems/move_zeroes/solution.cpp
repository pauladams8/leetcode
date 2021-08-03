class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int n : nums)
            if (n != 0) nums[j++] = n;
        while (j < nums.size())
            nums[j++] = 0;
    }
};