typedef long long ll;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> stk;
        auto pop = [&]() {
            ll top = stk.top();
            stk.pop();
            return top;
        };
        for (string tok : tokens) {
            if (tok == "+") {
                stk.push(pop() + pop());
            } else if (tok == "-") {
                ll rhs = pop(), lhs = pop();
                stk.push(lhs - rhs);
            } else if (tok == "*") {
                stk.push(pop() * pop());
            } else if (tok == "/") {
                ll rhs = pop(), lhs = pop();
                stk.push(lhs / rhs);
            } else {
                stk.push(stoi(tok));
            }
        }
        return stk.top();
    }
};