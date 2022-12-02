class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        queue<int> q;
        for (int i = 1; i * i <= n; i++) {
            int sq = i * i;
            if (sq == n) return 1;
            squares.push_back(sq);
            q.push(sq);
        }
        int count = 2;
        while (!q.empty()) {
            int countSize = q.size();
            for (int i = 0; i < countSize; i++) {
                int sum = q.front();
                q.pop();
                for (int sq : squares) {
                    int newSum = sum + sq;
                    if (newSum == n) return count;
                    q.push(newSum);
                }
            }
            count++;
        }
        return -1;
    }
};