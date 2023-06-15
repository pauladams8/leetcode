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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q, next;
        int ans = 0, level = 1, maxSum = INT_MIN;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int sum = 0;
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    next.push(node->left);
                if (node->right)
                    next.push(node->right);
            }
            if (sum > maxSum)
                ans = level, maxSum = sum;
            level++;
            swap(q, next);
        }
        return ans;
    }
};