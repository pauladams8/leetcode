class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        map<vector<int>, int> freq;
        for (int j = 0; j < n; j++) {
            vector<int> col(n);
            for (int i = 0; i < n; i++)
                col[i] = grid[i][j];
            freq[col]++;
        }
        for (int i = 0; i < n; i++)
            ans += freq[grid[i]];
        return ans;
    }
};