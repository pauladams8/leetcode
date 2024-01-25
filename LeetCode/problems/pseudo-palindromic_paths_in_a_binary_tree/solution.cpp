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
    int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode *root, int freq) {
        if (!root)
            return 0;
        freq ^= 1 << root->val;
        if (!root->left && !root->right)
            return (freq & (freq - 1)) == 0;
        return dfs(root->left, freq) + dfs(root->right, freq);
    }
};