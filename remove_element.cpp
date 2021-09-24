#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i - s] = nums[i];
            if (nums[i] == val) ++s;
        }
        return nums.size() - s;
    }
};