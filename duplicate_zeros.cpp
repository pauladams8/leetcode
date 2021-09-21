#include <vector>

class Solution {
public:
    void duplicateZeros(std::vector<int>& a) {
        int count = 0, n = a.size();
        for (int n : a) {
            if (n == 0)
                count++;
        }
        for (int i = n - 1; i >= 0 && count > 0; i--) {
            if (a[i] == 0) {
                if (i + count < n)
                    a[i + count] = 0;
                count--;
            }
            if (i + count < n)
                a[i + count] = a[i];
        }
    }
};