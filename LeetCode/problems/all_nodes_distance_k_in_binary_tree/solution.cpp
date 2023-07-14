/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<bool> seen(501);
        vector<vector<int>> adj(501);
        dfs(nullptr, root, adj);
        queue<int> q, q1;
        q.push(target->val);
        seen[target->val] = true;
        int distance = 0;
        while (distance < k && !q.empty()) {
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int next : adj[node]) {
                    if (!seen[next]) {
                        q1.push(next);
                        seen[next] = true;
                    }
                }
            }
            distance++;
            swap(q, q1);
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
private:
    void dfs(TreeNode *parent, TreeNode *child, vector<vector<int>>& adj) {
        if (!child) {
            return;
        }
        if (parent) {
            adj[parent->val].push_back(child->val);
            adj[child->val].push_back(parent->val);
        }
        dfs(child, child->left, adj);
        dfs(child, child->right, adj);
    }
};