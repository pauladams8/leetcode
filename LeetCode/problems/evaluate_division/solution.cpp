class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        unordered_map<string, vector<pair<string, double>>> prod;
        for (int i = 0; i < n; i++) {
            prod[equations[i][0]].push_back({ equations[i][1], values[i] });
            prod[equations[i][1]].push_back({ equations[i][0], 1 / values[i] });
        }
        vector<double> ans(m);
        for (int i = 0; i < m; i++) {
            unordered_set<string> seen;
            ans[i] = div(queries[i][0], queries[i][1], prod, seen);
        }
        return ans;
    }
private:
    double div(string& x, string& y, unordered_map<string, vector<pair<string, double>>> prod, unordered_set<string>& seen) {
        if (prod.find(x) == prod.end() || prod.find(y) == prod.end())
            return -1;
        if (seen.find(x) != seen.end())
            return -1;
        if (x == y)
            return 1;
        seen.insert(x);
        for (auto [z, val] : prod[x]) {
            double res = div(z, y, prod, seen);
            if (res < 0) continue;
            return val * res;
        }
        return -1;
    }
};