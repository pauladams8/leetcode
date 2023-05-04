class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common = 0;
        vector<int> seenA(n + 1), seenB(n + 1), C(n);
        for (int i = 0; i < n; i++) {
            seenA[A[i]] = true;
            seenB[B[i]] = true;
            if (seenA[B[i]])
                common++;
            if (A[i] != B[i] && seenB[A[i]])
                common++;
            C[i] = common;
        }
        return C;
    }
};