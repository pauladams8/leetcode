class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int col = 0; col < strs[0].size(); col++) {
            for (int row = 1; row < strs.size(); row++) {
                if (strs[row][col] < strs[row - 1][col]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};