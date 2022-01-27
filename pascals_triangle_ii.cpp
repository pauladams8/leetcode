#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        static std::vector<std::vector<int>> triangle;
        while (rowIndex >= triangle.size()) {
            std::vector<int> row(triangle.size() + 1);
            for (int col = 0; col <= triangle.size(); col++) {
                if (col == 0 || col == triangle.size()) row[col] = 1;
                else row[col] = triangle[triangle.size() - 1][col - 1] + triangle[triangle.size() - 1][col];
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};
