/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node *node) {
        unordered_map<Node*, Node*> map;
        return cloneGraph(node, map);
    }
private:
    Node* cloneGraph(Node *node, unordered_map<Node*, Node*>& map) {
        if (!node) return nullptr;
        auto& clone = map[node];
        if (clone) return clone;
        clone = new Node(*node);
        for (auto& neighbor : clone->neighbors)
            neighbor = cloneGraph(neighbor, map);
        return clone;
    }
};