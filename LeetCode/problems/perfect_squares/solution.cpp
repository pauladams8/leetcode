class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        vector<bool> seen(n + 1);
        q.push(0);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int sum = q.front();
                q.pop();
                if (sum == n)
                    return count;
                for (int j = 1; sum + j * j <= n; j++) {
                    if (seen[sum + j * j])
                        continue;
                    q.push(sum + j * j);
                    seen[sum + j * j] = true;
                }
            }
            count++;
        }
        return -1;
    }
};