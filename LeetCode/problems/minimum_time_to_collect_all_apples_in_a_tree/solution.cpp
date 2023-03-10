class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> newEdges(n);
        for (auto edge : edges)
            newEdges[edge[0]].push_back(edge[1]), newEdges[edge[1]].push_back(edge[0]);
        vector<bool> seen(n);
        return minTime(0, newEdges, hasApple, seen);
    }
private:
    int minTime(int start, vector<vector<int>>& edges, vector<bool>& hasApple, vector<bool>& seen) {
        seen[start] = true;
        int ans = 0;
        for (int newStart : edges[start]) {
            if (seen[newStart])
                continue;
            int time = minTime(newStart, edges, hasApple, seen);
            if (time || hasApple[newStart])
                ans += time + 2;
        }
        return ans;
    }
};