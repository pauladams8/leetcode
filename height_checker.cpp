#include <vector>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        vector<int> freq(100);
        for (int n : heights)
            freq[n - 1]++;
        int i = 0, count = 0;
        for (int n : heights) {
            while (freq[i] == 0)
                i++;
            if (n != i + 1)
                count++;
            freq[i]--;
        }
        return count;
    }
};