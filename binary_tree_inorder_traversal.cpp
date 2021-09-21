#include <vector>
#include <stack>
#include <tree_node.h>

class Solution {
    public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};