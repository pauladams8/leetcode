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
    int postorderIndex;
    TreeNode* buildNode(unordered_map<int, int>& inorderMap, vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[postorderIndex--]);
        int inorderIndex = inorderMap[root->val];
        root->right = buildNode(inorderMap, postorder, inorderIndex + 1, right);
        root->left = buildNode(inorderMap, postorder, left, inorderIndex - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        postorderIndex = postorder.size() - 1;
        return buildNode(inorderMap, postorder, 0, inorder.size() - 1);
    }
};