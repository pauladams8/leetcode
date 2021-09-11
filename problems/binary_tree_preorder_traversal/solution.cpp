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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        if (root)
            stack.push(root);
        while (!stack.empty()) {
            TreeNode* n = stack.top();
            stack.pop();
            result.push_back(n->val);
            if (n->right)
                stack.push(n->right);
            if (n->left)
                stack.push(n->left);
        }
        return result;
    }
};