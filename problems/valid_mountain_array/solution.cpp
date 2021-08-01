class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        bool increasing = true;
        for (int i = 1; i < arr.size(); ++i) {
            if (increasing) {
                if (arr[i] <= arr[i - 1]) {
                    if (i == 1)
                        return false;
                    if (arr[i] == arr[i - 1])
                        return false;
                    increasing = false;
                }
                if (increasing && i == arr.size() - 1)
                    return false;
            } else {
                if (arr[i] >= arr[i - 1])
                    return false;
            }
        }
        return true;
    }
};