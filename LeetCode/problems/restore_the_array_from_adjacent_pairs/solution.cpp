class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> prefix;
        unordered_set<int> seen;
        for (auto& [num, adj_to_num] : adj) {
            if (adj_to_num.size() == 1 &&
                dfs(num, prefix, seen, adj)) {
                break;
            }
        }
        return prefix;
    }
private:
    bool dfs(int num, vector<int>& prefix, unordered_set<int>& seen, unordered_map<int, vector<int>>& adj) {
        if (seen.find(num) != seen.end()) {
            return false;
        }
        seen.insert(num);
        prefix.push_back(num);
        if (prefix.size() == adj.size()) {
            return true;
        }
        for (auto next : adj[num]) {
            if (dfs(next, prefix, seen, adj)) {
                return true;
            }
        }
        seen.erase(num);
        prefix.pop_back();
        return false;
    }
};