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
    unordered_map<int, int> inorderMap;
    int preorderIndex;
    TreeNode* buildNode(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderIndex++]);
        int inorderIndex = inorderMap[root->val];
        root->left = buildNode(preorder, left, inorderIndex - 1);
        root->right = buildNode(preorder, inorderIndex + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        preorderIndex = 0;
        return buildNode(preorder, 0, inorder.size() - 1);
    }
};