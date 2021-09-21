#include <vector>
#include <stack>
#include <tree_node.h>

class Solution {
    public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> stack;
        if (root)
            stack.push(root);
        while (!stack.empty()) {
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            if (root->left)
                stack.push(root->left);
            if (root->right)
                stack.push(root->right);
        }
        int i = 0, j = result.size() - 1;
        while (i < j)
            std::swap(result[i++], result[j++]);
        return result;
    }
};