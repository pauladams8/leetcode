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
    int longestZigZag(TreeNode* root) {
        return longestZigZag(root, "left").second;
    }
private:
    pair<int, int> longestZigZag(TreeNode *root, string direction) {
        if (!root) return { 0, 0 };
        auto [withLeft, withoutLeft] = longestZigZag(root->left, "right");
        auto [withRight, withoutRight] = longestZigZag(root->right, "left");
        int with = (direction == "left" ? withLeft : withRight) + 1;
        int without = max(max(withLeft, withoutLeft), max(withRight, withoutRight));
        return { with, without };
    }
};