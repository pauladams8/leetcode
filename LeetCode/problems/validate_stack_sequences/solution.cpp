class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for (int n : popped) {
            if (!stk.empty() && stk.top() == n) {
                stk.pop();
                continue;
            }
            while (i < pushed.size() && pushed[i] != n)
                stk.push(pushed[i++]);
            if (i >= pushed.size())
                return false;
            i++;
        }
        return true;
    }
};