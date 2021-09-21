#include "tree_node.h"

class Solution {
    public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};