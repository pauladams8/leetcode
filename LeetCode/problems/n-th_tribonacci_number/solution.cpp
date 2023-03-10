class Solution {
public:
    int tribonacci(int n) {
        static vector<int> trib = { 0, 1, 1 };
        while (trib.size() <= n)
            trib.push_back(trib[trib.size() - 3] + trib[trib.size() - 2] + trib[trib.size() - 1]);
        return trib[n];
    }
};