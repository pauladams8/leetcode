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
    TreeNode* buildNode(int left, int right, vector<int>& postorder) {
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        return buildNode(0, inorder.size() - 1, postorder);
    }
};