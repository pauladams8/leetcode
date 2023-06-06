class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 2; i < n; i++)
            if (arr[i] - arr[i - 1] != arr[1] - arr[0])
                return false;
        return true;
    }
};