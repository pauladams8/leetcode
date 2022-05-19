class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int msf = 0;
        vector<vector<int>> paths(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            paths[i] = vector<int>(matrix[i].size(), 0);
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                msf = max(msf, longestIncreasingPath(matrix, paths, i, j, -1));
        return msf;
    }
private:
    int longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& paths, int i, int j, int prev) {
        if (i < 0 || i >= matrix.size())
            return 0;
        if (j < 0 || j >= matrix[i].size())
            return 0;
        if (matrix[i][j] <= prev)
            return 0;
        if (paths[i][j])
            return paths[i][j];
        vector<pair<int, int>> adj = {
            { i - 1, j },
            { i, j + 1 },
            { i + 1, j },
            { i, j - 1 }
        };
        for (auto& [i1, j1] : adj)
            paths[i][j] = max(paths[i][j], longestIncreasingPath(matrix, paths, i1, j1, matrix[i][j]) + 1);
        return paths[i][j];
    }
};