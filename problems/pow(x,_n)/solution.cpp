class Solution {
public:
    double myPow(double x, int n) {
        double pow = 1;
        for (int i = 0; i < abs((double) n) && pow != 0 && abs(x) != 1; i++)
            pow = n < 0 ? pow / abs(x) : pow * abs(x);
        return x < 0 && n % 2 != 0 ? -pow : pow;
    }
};