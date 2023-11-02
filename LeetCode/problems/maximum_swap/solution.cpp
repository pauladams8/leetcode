class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size(), max_digit = INT_MIN, max_idx = -1, left_idx = -1, right_idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > max_digit) {
                max_digit = s[i];
                max_idx = i;
            } else if (s[i] < max_digit) {
                left_idx = i;
                right_idx = max_idx;
            }
        }
        if (left_idx != -1 && right_idx != -1) {
            swap(s[left_idx], s[right_idx]);
        }
        return stoi(s);
    }
};