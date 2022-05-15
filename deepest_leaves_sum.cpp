#include <queue>
#include <utility>
#include "tree_node.h"

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        std::queue<TreeNode*> q, next;
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
            q = std::move(next);
        }
        return sum;
    }
};
