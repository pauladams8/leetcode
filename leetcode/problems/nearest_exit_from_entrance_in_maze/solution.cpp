class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({ entrance[0], entrance[1] });
        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [row, col] = q.front();
                q.pop();
                if (row < 0 || row >= maze.size())
                    continue;
                if (col < 0 || col >= maze[row].size())
                    continue;
                if (maze[row][col] != '.')
                    continue;
                if ((row == 0 || row == maze.size() - 1) && steps)
                    return steps;
                if ((col == 0 || col == maze[row].size() - 1) && steps)
                    return steps;
                maze[row][col] = '+';
                q.push({ row - 1, col });
                q.push({ row, col + 1 });
                q.push({ row + 1, col });
                q.push({ row, col - 1 });
            }
            steps++;
        }
        return -1;
    }
};