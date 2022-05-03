#include <vector>
#include "tree_node.h"

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    std::vector<TreeNode*> generateTrees(int l, int r) {
        if (l > r) return { nullptr };
        std::vector<TreeNode*> trees;
        for (int i = l; i <= r; i++)
            for (TreeNode* left : generateTrees(l, i - 1))
                for (TreeNode* right : generateTrees(i + 1, r))
                    trees.push_back(new TreeNode(i, left, right));
        return trees;
    }
};
