class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> answer(grid[0].size());
        for (int ball = 0; ball < grid[0].size(); ball++)
            answer[ball] = findBall(grid, ball);
        return answer;
    }
private:
    int findBall(vector<vector<int>>& grid, int ball) {
        int col = ball;
        for (int row = 0; row < grid.size(); row++)
            if (isValid(grid, col + grid[row][col]) && grid[row][col + grid[row][col]] == grid[row][col])
                col += grid[row][col];
            else return -1;
        return col;
    }
    
    bool isValid(vector<vector<int>>& grid, int col) {
        return col >= 0 && col < grid[0].size();
    }
};