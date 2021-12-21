#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() : val(0), neighbors() {}
    Node(int val) : val(val), neighbors() {}
    Node(int val, std::vector<Node*> neighbors) : val(val), neighbors(neighbors) {}
};

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
