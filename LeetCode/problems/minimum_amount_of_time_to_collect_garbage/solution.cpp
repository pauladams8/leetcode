class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), ans = 0;
        vector<int> time_to(n);
        vector<pair<string, int>> last = {
            { "M", 0 },
            { "P", 0 },
            { "G", 0 }
        };
        for (int i = 1; i < n; i++) {
            time_to[i] = time_to[i - 1] + travel[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (auto& [m, l] : last) {
                if (garbage[i].find(m) != string::npos) {
                    l = i;
                }
            }
            ans += garbage[i].size();
        }
        for (auto& [m, l] : last) {
            ans += time_to[l];
        }
        return ans;
    }
};