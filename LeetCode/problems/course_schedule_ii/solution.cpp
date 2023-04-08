class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites)
            adj[edge[0]].push_back(edge[1]);
        vector<int> ans, seen(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!findOrder(i, ans, seen, adj))
                break;
            if (ans.size() == numCourses)
                return ans;
        }
        return {};
    }
private:
    bool findOrder(int course, vector<int>& ans, vector<int>& seen, vector<vector<int>>& adj) {
        if (seen[course])
            return seen[course] == 1;
        seen[course] = -1;
        for (auto req : adj[course])
            if (!findOrder(req, ans, seen, adj))
                return false;
        ans.push_back(course);
        seen[course] = 1;
        return true;
    }
};