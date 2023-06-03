typedef long long ll;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n);
            ans = max(ans, dfs(bombs, i, seen));
        }
        return ans;
    }
private:
    int dfs(vector<vector<int>>& bombs, int i, vector<bool>& seen) {
        if (seen[i]) return 0;
        seen[i] = true;
        int n = bombs.size(), ans = 1;
        for (int j = 0; j < n; j++)
            if (canDetonate(bombs[i], bombs[j]))
                ans += dfs(bombs, j, seen);
        return ans;
    }
    
    bool canDetonate(vector<int>& a, vector<int>& b) {
        ll distance = pow((ll)a[0] - b[0], 2) + pow((ll)a[1] - b[1], 2);
        return distance <= pow((ll)a[2], 2);
    }
};