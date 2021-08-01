class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), m = arr[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            int c = arr[i];
            if (i == n - 1)
                arr[i] = -1;
            else
                arr[i] = m;
            if (c > m)
                m = c;
        }
        return arr;
    }
};