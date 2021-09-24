#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                swap(nums[i], nums[j++]);
        }
        return nums;
    }
};