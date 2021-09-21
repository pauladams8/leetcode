#include <vector>
#include <queue>
#include <tree_node.h>

class Solution {
    public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            int n = q.size();
            std::vector<int> level;
            level.reserve(n);
            for (int i = 0; i < n; i++) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            result.push_back(level);
            level.clear();
        }
        return result;
    }
};