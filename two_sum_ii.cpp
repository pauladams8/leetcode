#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            int left = i + 1, right = numbers.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (complement < numbers[mid])
                    right = mid - 1;
                else if (complement > numbers[mid])
                    left = mid + 1;
                else
                    return {i + 1, mid + 1};
            }
        }
        return {};
    }
};
