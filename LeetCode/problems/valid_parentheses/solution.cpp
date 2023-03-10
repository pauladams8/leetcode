class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') stack.push(c);
            if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) return false;
                char cur = stack.top();
                if (cur == '(' && c != ')') return false;
                if (cur == '[' && c != ']') return false;
                if (cur == '{' && c != '}') return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};