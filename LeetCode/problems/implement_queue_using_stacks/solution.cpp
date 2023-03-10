class MyQueue {
    stack<int> pushStack, popStack;
public:
    MyQueue() {}
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        int front = peek();
        popStack.pop();
        return front;
    }
    
    int peek() {
        if (popStack.empty()) {
            while (!pushStack.empty()) {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }
        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */