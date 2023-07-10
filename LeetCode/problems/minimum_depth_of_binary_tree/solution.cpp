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
    int minDepth(TreeNode* root) {
        int depth = 1;
        queue<TreeNode*> q, next;
        if (root)
            q.push(root);
        while (!q.empty()) {
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            }
            depth++;
            swap(q, next);
        }
        return 0;
    }
};