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

typedef long long ll;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, ll min, ll max) {
        if (!root)
            return true;
        if (root->val <= min)
            return false;
        if (root->val >= max)
            return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};