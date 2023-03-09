class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int pile : piles)
            right = max(right, pile);
        while (left < right) {
            int mid = (left + right) / 2;
            if (canEatWithin(h, mid, piles))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool canEatWithin(int hours, int k, vector<int>& piles) {
        int hoursRequired = 0;
        for (int pile : piles) {
            hoursRequired += (pile + k - 1) / k;
            if (hoursRequired > hours)
                return false;
        }
        return true;
    }
};