class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (int n : nums)
            if (n % 2 == 0)
                sum += n;
        vector<int> answer;
        answer.reserve(queries.size());
        for (vector<int>& query : queries) {
            if (nums[query[1]] % 2 && query[0] % 2)
                sum += nums[query[1]] + query[0];
            else if (nums[query[1]] % 2 == 0 && query[0] % 2 == 0)
                sum += query[0];
            else if (nums[query[1]] % 2 == 0 && query[0] % 2)
                sum -= nums[query[1]];
            nums[query[1]] += query[0];
            answer.push_back(sum);
        }
        return answer;
    }
};