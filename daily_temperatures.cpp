#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size());
        for (int day = temperatures.size() - 1; day >= 0; day--) {
            for (int futureDay = day + 1; futureDay < answer.size(); futureDay += answer[futureDay]) {
                if (temperatures[futureDay] > temperatures[day]) {
                    answer[day] = futureDay - day;
                    break;
                }
                if (answer[futureDay] == 0) {
                    answer[day] = 0;
                    break;
                }
            }
        }
        return answer;
    }
};
