class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> seen(n);
        vector<vector<int>> newEdges(n);
        for (vector<int>& edge : edges)
            newEdges[edge[0]].push_back(edge[1]), newEdges[edge[1]].push_back(edge[0]);
        return validPath(source, destination, newEdges, seen);
    }
private:
    bool validPath(int source, int destination, vector<vector<int>>& edges, vector<bool>& seen) {
        if (source == destination)
            return true;
        if (seen[source])
            return false;
        seen[source] = true;
        for (int newSource : edges[source])
            if (validPath(newSource, destination, edges, seen))
                return true;
        return false;
    }
};