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
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> freq(10);
        return pseudoPalindromicPaths(root, freq);
    }
private:
    int pseudoPalindromicPaths(TreeNode* root, vector<int>& freq) {
        if (!root) return 0;
        freq[root->val]++;
        if (!root->left && !root->right) {
            bool odd = false;
            for (int i = 1; i <= 9; i++)
                if (freq[i] % 2)
                    if (odd) return back(root, freq, 0);
                    else odd = true;
            return back(root, freq, 1);
        }
        return back(root, freq, pseudoPalindromicPaths(root->left, freq) + pseudoPalindromicPaths(root->right, freq));
    }
    
    int back(TreeNode* root, vector<int>& freq, int ret) {
        freq[root->val]--;
        return ret;
    }
};