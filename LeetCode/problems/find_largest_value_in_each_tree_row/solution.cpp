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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q, q1;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int level_max = INT_MIN;
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                level_max = max(level_max, node->val);
                if (node->left)
                    q1.push(node->left);
                if (node->right)
                    q1.push(node->right);
            }
            swap(q, q1);
            ans.push_back(level_max);
        }
        return ans;
    }
};