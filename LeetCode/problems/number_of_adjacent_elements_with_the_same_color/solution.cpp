class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m = queries.size(), cnt = 0;
        vector<int> nums(n), answer(m);
        for (int i = 0; i < m; i++) {
            int j = queries[i][0], color = queries[i][1];
            answer[i] = cnt;
            if (color == nums[j])
                continue;
            if (j > 0 && color == nums[j - 1])
                cnt++;
            if (j > 0 && nums[j] && nums[j] == nums[j - 1])
                cnt--;
            if (j + 1 < n && color == nums[j + 1])
                cnt++;
            if (j + 1 < n && nums[j] && nums[j] == nums[j + 1])
                cnt--;
            nums[j] = color;
            answer[i] = cnt;
        }
        return answer;
    }
};