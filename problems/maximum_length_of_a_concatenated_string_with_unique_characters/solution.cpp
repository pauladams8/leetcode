class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bool> contains(26);
        return maxLength(arr, contains, 0);
    }
private:
    int maxLength(vector<string>& arr, vector<bool>& contains, int start) {
        if (start >= arr.size())
            return 0;
        int ans = 0;
        for (int i = start; i < arr.size(); i++) {
            vector<bool> newContains(contains);
            if (isFresh(arr[i], newContains))
                ans = max(ans, maxLength(arr, newContains, i + 1) + (int) arr[i].size());
        }
        return ans;
    }
private:
    bool isFresh(string& s, vector<bool>& contains) {
        for (char c : s) {
            if (contains[c - 'a'])
                return false;
            contains[c - 'a'] = true;
        }
        return true;
    }
};