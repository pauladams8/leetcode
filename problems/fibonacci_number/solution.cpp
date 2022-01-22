class Solution {
public:
    int fib(int n) {
        static std::vector<int> cache(31, -1);
        if (cache[n] != -1) return cache[n];
        if (n <= 1) cache[n] = n;
        else cache[n] = fib(n - 1) + fib(n - 2);
        return cache[n];
    }
};