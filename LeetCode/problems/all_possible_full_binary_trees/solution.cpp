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
    vector<TreeNode*> allPossibleFBT(int n) {
        static vector<vector<TreeNode*>> dp;
        if (n == 1)
            return { new TreeNode() };
        if (n % 2 == 0)
            return {};
        if (dp.size() <= n)
            dp.resize(n + 1);
        if (!dp[n].empty())
            return dp[n];
        vector<TreeNode*> ans;
        for (int i = 1; i < n; i += 2)
            for (auto left : allPossibleFBT(i))
                for (auto right : allPossibleFBT(n - i - 1))
                    ans.push_back(new TreeNode(0, left, right));
        return dp[n] = ans;
    }
};