#include <vector>

class Solution {
public:
    int fib(int n) {
        static std::vector<int> cache;
        while (n >= cache.size()) {
            int i = cache.size();
            if (i <= 1) cache.push_back(i);
            else cache.push_back(cache[i - 1] + cache[i - 2]);
        }
        return cache[n];
    }
};
