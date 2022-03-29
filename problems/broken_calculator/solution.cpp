class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int min = 0;
        while (startValue != target) {
            if (startValue < target && target % 2 == 0) target /= 2;
            else target++;
            min++;
        }
        return min;
    }
};