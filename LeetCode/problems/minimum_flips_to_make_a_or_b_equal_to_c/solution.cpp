class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a || b || c) {
            int numOnes = (a & 1) + (b & 1);
            if (c & 1)
                ans += !numOnes;
            else ans += numOnes;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};