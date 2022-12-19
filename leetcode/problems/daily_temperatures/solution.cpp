class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < temperatures.size(); j += answer[j]) {
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
                if (!answer[j]) {
                    break;
                }
            }
        }
        return answer;
    }
};