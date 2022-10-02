class Solution {
    const int mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> cache(n + 1, vector<int>(target + 1, -1));
        return numRollsToTarget(n, k, target, cache);
    }
private:
    int numRollsToTarget(int n, int k, int target, vector<vector<int>>& cache) {
        if (target == 0) return n == 0 ? 1 : 0;
        if (target < 0) return 0;
        if (n == 0) return 0;
        if (cache[n][target] != -1)
            return cache[n][target];
        cache[n][target] = 0;
        for (int i = 1; i <= k; i++)
            cache[n][target] = (cache[n][target] + numRollsToTarget(n - 1, k, target - i, cache)) % mod;
        return cache[n][target];
    }
};