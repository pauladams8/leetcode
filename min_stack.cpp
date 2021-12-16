#include <vector>

class MinStack {
    std::vector<int> contents;
    int minIndex;
public:
    MinStack() : minIndex(-1) {}
    
    void push(int val) {
        contents.push_back(val);
        if (minIndex == -1 || val < contents[minIndex]) minIndex = contents.size() - 1;
    }
    
    void pop() {
        contents.pop_back();
        if (minIndex < contents.size()) return;
        for (int i = 0; i < contents.size(); i++) {
            if (minIndex >= contents.size() || contents[i] < contents[minIndex]) minIndex = i;
        }
    }
    
    int top() {
        return contents.back();
    }
    
    int getMin() {
        return minIndex == -1 ? INT_MAX : contents[minIndex];
    }
};
