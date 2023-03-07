typedef long long ll;

class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        ll left = 0, right = LLONG_MAX;
        for (ll trip : time)
            right = min(right, trip);
        right *= totalTrips;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (canComplete(totalTrips, mid, time))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    bool canComplete(int totalTrips, ll time, vector<int>& trips) {
        int tripsCount = 0;
        for (int trip : trips) {
            tripsCount += time / trip;
            if (tripsCount >= totalTrips)
                return true;
        }
        return false;
    }
};