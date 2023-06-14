typedef long long ll;

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
    int getMinimumDifference(TreeNode* root) {
        ll ans = INT_MAX;
        dfs(root, ans);
        return ans;
    }
private:
    pair<ll, ll> dfs(TreeNode *root, ll& ans) {
        if (!root) return { INT_MAX, INT_MIN };
        pair<ll, ll> left = dfs(root->left, ans), right = dfs(root->right, ans);
        ans = min(ans, min(root->val - left.second, right.first - root->val));
        return { min((ll)root->val, left.first), max((ll)root->val, right.second) };
    }
};