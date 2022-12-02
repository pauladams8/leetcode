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
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> map;
        return cloneNode(node, map);
    }
private:
    Node* cloneNode(Node* node, std::unordered_map<Node*, Node*>& map) {
        if (!node) return nullptr;
        Node*& newNode = map[node];
        if (newNode) return newNode;
        newNode = new Node(*node);
        for (int i = 0; i < newNode->neighbors.size(); i++)
            newNode->neighbors[i] = cloneNode(newNode->neighbors[i], map);
        return newNode;
    }
};