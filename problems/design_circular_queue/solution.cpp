class MyCircularQueue {
    vector<int> contents;
    int front;
    int rear;
public:
    MyCircularQueue(int k) : contents(k), front(-1), rear(-1) {}
    
    bool enQueue(int value) {
        int newRear = (rear + 1) % contents.size();
        if (newRear == front) return false;
        contents[newRear] = value;
        rear = newRear;
        if (front == -1) front = 0;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = -1;
            rear = -1;
            return true;
        }
        front = (front + 1) % contents.size();
        return true;
    }
    
    int Front() {
        return front == -1 ? -1 : contents[front];
    }
    
    int Rear() {
        return rear == -1 ? -1 : contents[rear];
    }
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % contents.size() == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */