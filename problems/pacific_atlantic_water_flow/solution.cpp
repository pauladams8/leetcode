class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> canFlowPacific(heights.size(), vector<bool>(heights[0].size())), canFlowAtlantic(heights.size(), vector<bool>(heights[0].size()));
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, 0, canFlowPacific);
            dfs(heights, i, heights[i].size() - 1, canFlowAtlantic);
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, 0, j, canFlowPacific);
            dfs(heights, heights.size() - 1, j, canFlowAtlantic);
        }
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); i++)
            for (int j = 0; j < heights[i].size(); j++)
                if (canFlowPacific[i][j] && canFlowAtlantic[i][j])
                    res.push_back({ i, j });
        return res;
    }
private:
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& seen) {
        if (seen[i][j]) return;
        seen[i][j] = true;
        vector<pair<int, int>> directions = {
            { i - 1, j },
            { i, j + 1 },
            { i + 1, j },
            { i, j - 1 }
        };
        for (auto [ii, jj] : directions) {
            if (ii < 0 || ii >= heights.size())
                continue;
            if (jj < 0 || jj >= heights[i].size())
                continue;
            if (heights[i][j] > heights[ii][jj])
                continue;
            dfs(heights, ii, jj, seen);
        }
    }
};