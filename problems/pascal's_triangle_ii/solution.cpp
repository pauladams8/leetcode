class Solution {
    std::vector<std::vector<int>> triangle;
public:
    Solution() : triangle(34) {
        for (int row = 0; row <= 33; row++) {
            triangle[row] = std::vector<int>(row + 1);
            for (int col = 0; col <= row; col++) {
                if (col == 0 || col == row) triangle[row][col] = 1;
                else triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
            }
        }
    }
    std::vector<int> getRow(int rowIndex) {
        return triangle[rowIndex];
    }
};