class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != '1') continue;
                count++;
                std::queue<std::pair<int, int>> q;
                q.push({ i, j });
                while (!q.empty()) {
                    auto point = q.front();
                    q.pop();
                    int i = point.first, j = point.second;
                    if (i < 0 || i >= grid.size() || j >= grid[i].size() || j < 0 || grid[i][j] != '1') continue;
                    grid[i][j] = '0';
                    q.push({ i - 1, j });
                    q.push({ i, j + 1 });
                    q.push({ i + 1, j });
                    q.push({ i, j - 1 });
                }
            }
        }
        return count;
    }
};
