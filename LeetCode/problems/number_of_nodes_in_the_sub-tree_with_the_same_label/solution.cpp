class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        vector<vector<int>> adj(n);
        for (auto edge : edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
        countSubTrees(0, -1, adj, labels, ans);
        return ans;
    }
private:
    vector<int> countSubTrees(int root, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ans) {
        vector<int> freq(26);
        freq[labels[root] - 'a'] = 1;
        for (int child : adj[root]) {
            if (child == parent)
                continue;
            vector<int> subFreq = countSubTrees(child, root, adj, labels, ans);
            for (int i = 0; i < 26; i++)
                freq[i] += subFreq[i];
        }
        ans[root] = freq[labels[root] - 'a'];
        return freq;
    }
};