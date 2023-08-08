class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> prefix;
        vector<vector<int>> ans;
        combine(1, n, k, prefix, ans);
        return ans;
    }
private:
    void combine(int from, int to, int k, vector<int>& prefix, vector<vector<int>>& ans) {
        if (prefix.size() == k) {
            ans.push_back(prefix);
            return;
        }
        for (int i = from; i <= to; i++) {
            prefix.push_back(i);
            combine(i + 1, to, k, prefix, ans);
            prefix.pop_back();
        }
    }
};