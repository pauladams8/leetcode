class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        std::vector<std::vector<int>> distances(mat.size());
        for (int row = 0; row < mat.size(); row++) {
            distances[row] = std::vector<int>(mat[row].size(), INT_MAX);
            for (int col = 0; col < mat[row].size(); col++) {
                if (mat[row][col] == 0) distances[row][col] = 0;
                if (row - 1 >= 0 && distances[row - 1][col] < distances[row][col]) distances[row][col] = distances[row - 1][col] + 1;
                if (col - 1 >= 0 && distances[row][col - 1] < distances[row][col]) distances[row][col] = distances[row][col - 1] + 1;
            }
        }
        for (int row = mat.size() - 1; row >= 0; row--) {
            for (int col = mat[row].size() - 1; col >= 0; col--) {
                if (col + 1 < mat[row].size() && distances[row][col + 1] < distances[row][col]) distances[row][col] = distances[row][col + 1] + 1;
                if (row + 1 < mat.size() && distances[row + 1][col] < distances[row][col]) distances[row][col] = distances[row + 1][col] + 1;
            }
        }
        return distances;
    }
};