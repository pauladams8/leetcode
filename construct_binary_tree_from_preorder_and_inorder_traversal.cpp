#include <vector>
#include <unordered_map>
#include "tree_node.h"

class Solution {
    std::unordered_map<int, int> inorderMap;
    int preorderIndex;
    TreeNode* buildNode(std::vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderIndex++]);
        int inorderIndex = inorderMap[root->val];
        root->left = buildNode(preorder, left, inorderIndex - 1);
        root->right = buildNode(preorder, inorderIndex + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        preorderIndex = 0;
        return buildNode(preorder, 0, inorder.size() - 1);
    }
};
