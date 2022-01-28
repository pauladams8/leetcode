#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        static std::vector<int> ways;
        while (n >= ways.size()) {
            int i = ways.size();
            if (i <= 1) ways.push_back(1);
            else ways.push_back(ways[i - 1] + ways[i - 2]);
        }
        return ways[n];
    }
};
