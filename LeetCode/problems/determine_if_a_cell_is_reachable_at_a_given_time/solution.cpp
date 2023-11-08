class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int shortest = max(abs(fx - sx), abs(fy - sy));
        return shortest == t || t - shortest > 1 || (t - shortest == 1 && shortest > 0);
    }
};