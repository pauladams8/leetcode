class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == high % 2)
            return (high - low + 1) / 2 + high % 2;
        return (high - low + 1) / 2;
    }
};