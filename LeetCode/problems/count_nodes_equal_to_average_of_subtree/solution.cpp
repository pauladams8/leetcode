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
    int averageOfSubtree(TreeNode* root) {
        auto [sum, total, cnt] = dfs(root);
        return cnt;
    }
private:
    array<int, 3> dfs(TreeNode *root) {
        if (!root)
            return { 0, 0 };
        auto [left_sum, left_total, left_cnt] = dfs(root->left);
        auto [right_sum, right_total, right_cnt] = dfs(root->right);
        int sum = left_sum + right_sum + root->val, total = left_total + right_total + 1, avg = sum / total, cnt = left_cnt + right_cnt + (root->val == avg);
        return { sum, total, cnt };
    }
};