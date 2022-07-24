class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
private:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int startRow, int startCol, int endRow, int endCol) {
        if (startRow > endRow)
            return false;
        if (startCol > endCol)
            return false;
        int midRow = (startRow + endRow) / 2, midCol = (startCol + endCol) / 2;
        if (target < matrix[midRow][midCol])
            return searchMatrix(matrix, target, startRow, startCol, midRow - 1, endCol) || searchMatrix(matrix, target, midRow, startCol, endRow, midCol - 1);
        else if (target > matrix[midRow][midCol])
            return searchMatrix(matrix, target, startRow, midCol + 1, endRow, endCol) || searchMatrix(matrix, target, midRow + 1, startCol, endRow, midCol);
        else return true;
    }
};