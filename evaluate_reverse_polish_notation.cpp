#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<string>& tokens) {
        std::stack<int> stack;
        for (std::string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = stack.top();
                stack.pop();
                int left = stack.top();
                stack.pop();
                if (token == "+") stack.push(left + right);
                if (token == "-") stack.push(left - right);
                if (token == "*") stack.push(left * right);
                if (token == "/") stack.push(left / right);
            } else stack.push(std::stoi(token));
        }
        return stack.top();
    }
};
