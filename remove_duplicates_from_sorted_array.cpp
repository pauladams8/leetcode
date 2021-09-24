#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i - count] = nums[i];
            if (i + 1 < n && nums[i] == nums[i + 1])
                count++;
        }
        return n - count;
    }
};