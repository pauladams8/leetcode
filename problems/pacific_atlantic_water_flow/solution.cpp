class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> seen(heights.size(), vector<bool>(heights[0].size())), canFlowPacific(heights.size(), vector<bool>(heights[0].size())), canFlowAtlantic(heights.size(), vector<bool>(heights[0].size()));
        for (int i = 0; i < heights.size(); i++)
            canFlowPacific[i][0] = true;
        for (int j = 0; j < heights[0].size(); j++)
            canFlowPacific[0][j] = true;
        for (int i = 0; i < heights.size(); i++)
            canFlowAtlantic[i][heights[0].size() - 1] = true;
        for (int j = 0; j < heights[0].size(); j++)
            canFlowAtlantic[heights.size() - 1][j] = true;
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (dfs(heights, seen, canFlowPacific, canFlowAtlantic, i, j))
                    res.push_back({ i, j });
                seen[i][j] = true;
            }
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& seen, vector<vector<bool>>& canFlowPacific, vector<vector<bool>>& canFlowAtlantic, int i, int j) {
        if (seen[i][j])
            return false;
        if (canFlowPacific[i][j] && canFlowAtlantic[i][j])
            return true;
        seen[i][j] = true;
        vector<pair<int, int>> directions = {
            { i - 1, j },
            { i, j + 1 },
            { i + 1, j },
            { i, j - 1 }
        };
        for (auto [ii, jj] : directions) {
            if (canFlowPacific[i][j] && canFlowAtlantic[i][j])
                break;
            if (ii < 0 || ii >= heights.size())
                continue;
            if (jj < 0 || jj >= heights[ii].size())
                continue;
            if (heights[ii][jj] > heights[i][j])
                continue;
            dfs(heights, seen, canFlowPacific, canFlowAtlantic, ii, jj);
            if (canFlowPacific[ii][jj])
                canFlowPacific[i][j] = true;
            if (canFlowAtlantic[ii][jj])
                canFlowAtlantic[i][j] = true;
        }
        seen[i][j] = false;
        return canFlowPacific[i][j] && canFlowAtlantic[i][j];
    }
};