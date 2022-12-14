class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0, c = 0;
        for (int house : nums)
            c = b, b = a, a = max(c + house, b);
        return a;
    }
};