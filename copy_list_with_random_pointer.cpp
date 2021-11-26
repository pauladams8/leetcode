class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(val) : val(val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> map;
        Node* newHead = new Node(*head);
        map.insert({ head, newHead });
        for (Node* n = newHead; n; n = n->next) {
            if (n->random) {
                auto newRandom = map.find(n->random);
                if (newRandom != map.end()) n->random = newRandom->second;
                else {
                    Node* oldRandom = n->random;
                    n->random = new Node(*oldRandom);
                    map.insert({ oldRandom, n->random });
                }
            }
            if (n->next) {
                auto newNext = map.find(n->next);
                if (newNext != map.end()) n->next = newNext->second;
                else {
                    Node* oldNext = n->next;
                    n->next = new Node(*n->next);
                    map.insert({ oldNext, n->next });
                }
            }
        }
        return newHead;
    }
};
