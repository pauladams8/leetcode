class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<bool> seen1(edges.size()), seen2(edges.size());
        bool ok = true;
        while (ok) {
            ok = false;
            if (node1 != -1 && node2 != -1 && seen1[node2] && seen2[node1])
                return min(node1, node2);
            if (node1 != -1 && !seen1[node1]) {
                if (seen2[node1])
                    return node1;
                seen1[node1] = true;    
                node1 = edges[node1];
                ok = true;
            }
            if (node2 != -1 && !seen2[node2]) {
                if (seen1[node2])
                    return node2;
                seen2[node2] = true;
                node2 = edges[node2];
                ok = true;
            }
        }
        return -1;
    }
};