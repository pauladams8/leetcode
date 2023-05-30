class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        for (int i = n - 2; i >= 0; i--)
            piles[i] += piles[i + 1];
        vector<vector<int>> cache(n, vector<int>(n + 1));
        return dfs(piles, 0, 1, cache);
    }
private:
    int dfs(vector<int>& piles, int i, int m, vector<vector<int>>& cache) {
        int n = piles.size(), ans = 0;
        if (i >= n) return 0;
        if (cache[i][m]) return cache[i][m];
        for (int x = 1; x <= 2 * m && i + x <= n; x++)
            ans = max(ans, piles[i] - dfs(piles, i + x, max(m, x), cache));
        return cache[i][m] = ans;
    }
};