#include <vector>
#include <string>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int count = 0;
        for (int n : nums) {
            if (std::to_string(n).size() % 2 == 0)
                count++;
        }
        return count;
    }
};