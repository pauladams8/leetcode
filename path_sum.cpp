#include "tree_node.h"

class Solution {
    public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right && root->val == targetSum)
            return true;
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};