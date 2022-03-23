#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int start = 0, end = height.size() - 1, max = 0;
        while (start < end) {
            max = std::max(max, std::min(height[start], height[end]) * (end - start));
            if (height[start] < height[end]) start++;
            else end--;
        }
        return max;
    }
};
