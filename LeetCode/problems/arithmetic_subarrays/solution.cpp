class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        vector<bool> answer(m);
        for (int i = 0; i < m; i++) {
            answer[i] = isSubseq(nums, l[i], r[i]);
        }
        return answer;
    }
private:
    int isSubseq(vector<int>& nums, int l, int r) {
        auto mn = *min_element(begin(nums) + l, begin(nums) + r + 1),
             mx = *max_element(begin(nums) + l, begin(nums) + r + 1);
        if ((mx - mn) % (r - l)) {
            return false;
        }
        int diff = (mx - mn) / (r - l);
        unordered_set<int> st(nums.begin() + l, nums.begin() + r + 1);
        for (int i = l; i <= r; i++) {
            if (nums[i] != mn &&
               st.find(nums[i] - diff) == st.end()) {
                return false;
            }
            if (diff) {
                st.erase(nums[i] - diff);
            }
        }
        return true;
    }
};