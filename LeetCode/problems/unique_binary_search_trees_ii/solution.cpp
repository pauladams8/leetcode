/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int lb, int ub) {
        static vector<vector<vector<TreeNode*>>> dp(9, vector<vector<TreeNode*>>(9));
        if (lb > ub)
            return { nullptr };
        if (!dp[lb][ub].empty())
            return dp[lb][ub];
        vector<TreeNode*> ans;
        for (int i = lb; i <= ub; i++)
            for (auto left : generateTrees(lb, i - 1))
                for (auto right : generateTrees(i + 1, ub))
                    ans.push_back(new TreeNode(i, left, right));
        return dp[lb][ub] = ans;
    }
};