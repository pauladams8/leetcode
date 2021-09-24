#include <vector>

class Solution {
public:
    bool validMountainArray(std::vector<int>& arr) {
        int n = arr.size(), i = 0, j = n - 1;
        while (i + 1 < n && arr[i + 1] > arr[i]) i++;
        while (j - 1 >= 0 && arr[j - 1] > arr[j]) j--;
        return i > 0 && i == j && j < n - 1;
    }
};