class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2, i = mid / n, j = mid % n;
            if (matrix[i][j] < target)
                left = mid + 1;
            else if (matrix[i][j] > target)
                right = mid - 1;
            else return true;
        }
        return false;
    }
};