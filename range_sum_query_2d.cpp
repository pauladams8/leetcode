#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix), sums(matrix.size(), vector<int>(matrix[0].size())) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sums[i][j] = matrix[i][j];
                if (i >= 1)
                    sums[i][j] += sums[i - 1][j];
                if (j >= 1)
                    sums[i][j] += sums[i][j - 1];
                if (i >= 1 && j >= 1)
                    sums[i][j] -= sums[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sums[row2][col2];
        if (row1 >= 1)
            sum -= sums[row1 - 1][col2];
        if (col1 >= 1)
            sum -= sums[row2][col1 - 1];
        if (row1 >= 1 && col1 >= 1)
            sum += sums[row1 - 1][col1 - 1];
        return sum;
    }
};
