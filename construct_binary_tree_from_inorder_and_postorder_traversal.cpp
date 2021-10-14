#include <vector>
#include <unordered_map>
#include "tree_node.h"

class Solution {
    std::unordered_map<int, int> inorderMap;
    TreeNode* buildNode(int left, int right, std::vector<int>& postorder) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        int i = inorderMap[root->val];
        root->right = buildNode(i + 1, right, postorder);
        root->left = buildNode(left, i - 1, postorder);
        return root;
    }
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        return buildNode(0, inorder.size() - 1, postorder);
    }
};