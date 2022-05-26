#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (uint32_t i = n; i; i /= 2)
            if (i % 2)
                count++;
        return count;
    }
};
