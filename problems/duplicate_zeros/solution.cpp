class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int c = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 0) ++c;
        }
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (arr[i] == 0) {
                if (i + c < arr.size())
                    arr[i + c] = arr[i];
                --c;
            }
            if (i + c < arr.size())
                arr[i + c] = arr[i];
        }
    }
};