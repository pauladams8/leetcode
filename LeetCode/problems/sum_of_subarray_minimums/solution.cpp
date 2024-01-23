class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        int n = arr.size(), ans = 0, mod = 1e9 + 7;
        stack<pair<int, int>> stk({{0, 0}});
        for (int i = 1; i < n; i++) {
            while (arr[stk.top().first] >= arr[i]) {
                stk.pop();
            }
            auto [j, sum] = stk.top();
            sum = (sum + arr[i] * (i - j)) % mod;
            ans = (ans + sum) % mod;
            stk.push({ i, sum });
        }
        return ans;
    }
};