class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bool> contains(26);
        return dfs(arr, 0, contains);
    }
private:
    int dfs(vector<string>& arr, int start, vector<bool>& contains) {
        int n = arr.size(), ans = 0;
        for (int i = start; i < n; i++) {
            vector<bool> new_contains(contains);
            if (ok(arr[i], new_contains)) {
                ans = max(ans, dfs(arr, i + 1, new_contains)
                          + (int)arr[i].size());
            }
        }
        return ans;
    }

    bool ok(string& s, vector<bool>& contains) {
        for (char c : s) {
            if (contains[c - 'a']) {
                return false;
            }
            contains[c - 'a'] = true;
        }
        return true;
    }
};