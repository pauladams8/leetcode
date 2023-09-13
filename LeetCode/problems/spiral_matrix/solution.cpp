class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), mn = m * n, i = 0, j = 0, k = 0, gap = 1;
        vector<int> ans(mn);
        while (k + 1 < mn) {
            while (k + 1 < mn && j + gap < n)
                ans[k++] = matrix[i][j++];
            while (k + 1 < mn && i + gap < m)
                ans[k++] = matrix[i++][j];
            while (k + 1 < mn && j >= gap)
                ans[k++] = matrix[i][j--];
            gap++;
            while (k + 1 < mn && i >= gap)
                ans[k++] = matrix[i--][j];
        }
        ans[k] = matrix[i][j];
        return ans;
    }
};