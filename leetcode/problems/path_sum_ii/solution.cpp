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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        pathSum(root, path, 0, targetSum, paths);
        return paths;
    }
private:
    void pathSum(TreeNode* root, vector<int>& path, int sum, int targetSum, vector<vector<int>>& paths) {
        if (!root) return;
        path.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right && sum == targetSum)
            paths.push_back(path);
        pathSum(root->left, path, sum, targetSum, paths);
        pathSum(root->right, path, sum, targetSum, paths);
        path.pop_back();
        sum -= root->val;
    }
};