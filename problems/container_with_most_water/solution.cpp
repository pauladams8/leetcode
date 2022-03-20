class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int start = 0, end = height.size() - 1, max = 0;
        while (start < end) {
            if (height[start] <= height[end]) {
                max = std::max(max, std::min(height[start], height[end]) * (end - start));
                start++;
            }
            if (height[end] <= height[start]) {
                max = std::max(max, std::min(height[start], height[end]) * (end - start));
                end--;
            }
        }
        return max;
    }
};