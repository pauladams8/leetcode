class Solution {
    const int mod = 1e9 + 7;
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>> apples(pizza.size() + 1, vector<int>(pizza[0].size() + 1));
        for (int i = 0; i < pizza.size(); i++)
            for (int j = 0; j < pizza[0].size(); j++)
                apples[i + 1][j + 1] = apples[i][j + 1] + apples[i + 1][j] - apples[i][j] + (pizza[i][j] == 'A');
        vector<vector<vector<int>>> cache(pizza.size(), vector<vector<int>>(pizza[0].size(), vector<int>(k + 1, -1)));
        return ways(pizza, apples, k, 0, 0, cache);
    }
    
    // determines if piece pizza[startRow..endRow)[startCol..endCol) has at least 1 apple
    bool hasApple(vector<vector<int>>& apples, int startRow, int startCol, int endRow, int endCol) {
        return apples[endRow][endCol] - apples[startRow][endCol] - apples[endRow][startCol] + apples[startRow][startCol];
    }
    
    int ways(vector<string>& pizza, vector<vector<int>>& apples, int k, int startRow, int startCol, vector<vector<vector<int>>>& cache) {
        if (!hasApple(apples, startRow, startCol, pizza.size(), pizza[0].size()))
            return 0;
        if (k == 1)
            return 1;
        auto& ans = cache[startRow][startCol][k];
        if (ans != -1)
            return ans;
        ans = 0;
        for (int i = startRow + 1; i < pizza.size(); i++)
            if (hasApple(apples, startRow, startCol, i, pizza[0].size()))
                ans = (ans + ways(pizza, apples, k - 1, i, startCol, cache)) % mod;
        for (int j = startCol + 1; j < pizza[0].size(); j++)
            if (hasApple(apples, startRow, startCol, pizza.size(), j))
                ans = (ans + ways(pizza, apples, k - 1, startRow, j, cache)) % mod;
        return ans;
    }
};