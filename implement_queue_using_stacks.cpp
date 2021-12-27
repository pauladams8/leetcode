#include <stack>

class MyQueue {
    std::stack<int> pushStack;
    std::stack<int> popStack;
public:
    MyQueue() {}
    
    void push(int x) {
        pushStack.push(x);
    }
    
    int pop() {
        int val = peek();
        popStack.pop();
        return val;
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
