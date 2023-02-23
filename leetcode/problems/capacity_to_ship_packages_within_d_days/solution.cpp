class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int w : weights)
            left = max(left, w), right += w;
        while (left < right) {
            int mid = (left + right) / 2;
            if (canShip(weights, mid, days))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }

    bool canShip(vector<int>& weights, int cap, int days) {
        int load = 0;
        for (int w : weights) {
            if (load + w > cap)
                load = 0, days--;
            if (!days) return false;
            load += w;
        }
        return true;
    }
};