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
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root, INT_MAX, INT_MIN);
    }
private:
    int maxAncestorDiff(TreeNode* root, int minVal, int maxVal) {
        if (!root) return maxVal - minVal;
        minVal = min(minVal, root->val), maxVal = max(maxVal, root->val);
        return max(maxAncestorDiff(root->left, minVal, maxVal), maxAncestorDiff(root->right, minVal, maxVal));
    }
};