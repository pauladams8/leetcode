#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int count = 0, max = 0;
        for (int n : nums) {
            if (n == 1)
                count++;
            else
                count = 0;
            if (count > max)
                max = count;
        }
        return max;
    }
};