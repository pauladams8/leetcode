class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer(queries.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); i++) {
            int count = 0, sum = 0;
            while (count < nums.size() && sum + nums[count] <= queries[i])
                sum += nums[count++];
            answer[i] = count;
        }
        return answer;
    }
};