#include <vector>
#include <stack>
#include <tree_node.h>

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
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