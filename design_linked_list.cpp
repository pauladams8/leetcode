class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    Node(int val, Node* next, Node* prev) : val(val), next(next), prev(prev) {}
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    int get(int index) {
        Node* n = getNode(index);
        return n ? n->val : -1;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        Node* next = getNode(index);
        Node* n = new Node(val, next, next ? next->prev : tail);
        if (n->next) n->next->prev = n;
        else tail = n;
        if (n->prev) n->prev->next = n;
        else head = n;
        size++;
    }
    
    void deleteAtIndex(int index) {
        Node* n = getNode(index);
        if (!n) return;
        if (n->next) n->next->prev = n->prev;
        else tail = n->prev;
        if (n->prev) n->prev->next = n->next;
        else head = n->next;
        size--;
    }
private:
    Node* getNode(int index) {
        if (index < 0) index += size;
        if (index < 0 || index >= size) return nullptr;
        float mid = ((float) size - 1) / 2;
        if (index > mid) {
            Node* n = tail;
            for (int i = size - 1; i > index; i--) n = n->prev;
            return n;
        }
        Node* n = head;
        for (int i = 0; i < index; i++) n = n->next;
        return n;
    }
};
