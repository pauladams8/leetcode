class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), max = -1;
        for (int i = n - 1; i >= 0; i--) {
            int m = arr[i];
            arr[i] = max;
            if (m > max)
                max = m;
        }
        return arr;
    }
};