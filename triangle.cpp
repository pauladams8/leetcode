#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size() + 1);
        for (int row = triangle.size() - 1; row >= 0; row--)
            for (int col = 0; col <= row; col++)
                dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
        return dp[0];
    }
};
