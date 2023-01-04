class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        for (int task : tasks)
            freq[task]++;
        int rounds = 0;
        for (auto [task, count] : freq) {
            while (count >= 3 && count != 4)
                count -= 3, rounds++;
            while (count >= 2)
                count -= 2, rounds++;
            if (count) return -1;
        }
        return rounds;
    }
};