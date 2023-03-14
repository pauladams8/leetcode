typedef long long ll;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left < right) {
            ll mid = left + (right - left) / 2 + 1, square = mid * mid;
            if (square < x)
                left = mid;
            else if (square > x)
                right = mid - 1;
            else return mid;
        }
        return left;
    }
};