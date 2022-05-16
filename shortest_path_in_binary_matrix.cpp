#include <utility>
#include <vector>
#include <queue>

class Solution {
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        q.push({ 0, 0 });
        for (int length = 1; !q.empty(); length++) {
            for (int k = 0, n = q.size(); k < n; k++) {
                auto [i, j] = q.front();
                q.pop();
                if (i < 0 || i >= grid.size())
                    continue;
                if (j < 0 || j >= grid[i].size())
                    continue;
                if (grid[i][j] != 0)
                    continue;
                grid[i][j] = 1;
                if (i == grid.size() - 1 && j == grid[i].size() - 1)
                    return length;
                q.push({ i - 1, j });
                q.push({ i - 1, j + 1 });
                q.push({ i, j + 1 });
                q.push({ i + 1, j + 1 });
                q.push({ i + 1, j });
                q.push({ i + 1, j - 1 });
                q.push({ i, j - 1 });
                q.push({ i - 1, j - 1 });
            }
        }
        return -1;
    }
};
