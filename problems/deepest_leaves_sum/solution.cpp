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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q, next;
        if (root)
            q.push(root);
        int sum;
        while (!q.empty()) {
            sum = 0;
            while (!q.empty()) {
                root = q.front();
                q.pop();
                sum += root->val;
                if (root->left)
                    next.push(root->left);
                if (root->right)
                    next.push(root->right);
            }
            q = move(next);
        }
        return sum;
    }
};