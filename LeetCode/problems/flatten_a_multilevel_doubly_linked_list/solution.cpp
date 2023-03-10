/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for (Node *n = head; n; n = n->next) {
            if (!n->child)
                continue;
            Node *child = n->child, *prev = nullptr;
            while (child) {
                flatten(child->child);
                prev = child;
                child = child->next;
            }
            prev->next = n->next;
            if (prev->next)
                prev->next->prev = prev;
            n->next = n->child;
            n->next->prev = n;
            n->child = nullptr;
        }
        return head;
    }
};