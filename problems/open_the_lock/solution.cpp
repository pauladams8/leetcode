class Solution {
public:
    int openLock(std::vector<string>& deadends, std::string targetStr) {
        std::set<std::vector<int>> deadendsSet;
        for (string deadendStr : deadends) {
            std::vector<int> deadend;
            for (char c : deadendStr) deadend.push_back(c - '0');
            deadendsSet.insert(deadend);
        }
        std::vector<int> target;
        for (char c : targetStr) target.push_back(c - '0');
        std::queue<std::vector<int>> queue;
        queue.push({ 0, 0, 0, 0 });
        int turnsRequired = 0;
        while (!queue.empty()) {
            int turnSize = queue.size();
            for (int i = 0; i < turnSize; i++) {
                std::vector<int> combination = queue.front();
                queue.pop();
                for (int d = 0; d < combination.size(); d++) {
                    if (combination[d] < 0) combination[d] += 10;
                    if (combination[d] > 9) combination[d] -= 10;
                }
                if (deadendsSet.find(combination) != deadendsSet.end()) continue;
                if (combination == target) return turnsRequired;
                for (int d = 0; d < combination.size(); d++) {
                    combination[d]++;
                    queue.push(combination);
                    combination[d]--;
                    combination[d]--;
                    queue.push(combination);
                    combination[d]++;
                }
                deadendsSet.insert(combination);
            }
            turnsRequired++;
        }
        return -1;
    }
};