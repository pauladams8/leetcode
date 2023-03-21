typedef long long ll;

class Solution {
public:
    ll zeroFilledSubarray(vector<int>& nums) {
        ll count = 0, total = 0;
        for (int n : nums)
            if (n) count = 0;
            else total += ++count;
        return total;
    }
};