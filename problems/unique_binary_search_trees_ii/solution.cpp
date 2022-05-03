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
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int l, int r) {
        if (l > r) return { nullptr };
        vector<TreeNode*> trees;
        for (int i = l; i <= r; i++)
            for (TreeNode* left : generateTrees(l, i - 1))
                for (TreeNode* right : generateTrees(i + 1, r))
                    trees.push_back(new TreeNode(i, left, right));
        return trees;
    }
};