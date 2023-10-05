class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, cnt = 0;
        for (int n : nums) {
            if (!cnt) {
                major = n;
            }
            cnt += n == major ? 1 : -1;
        }
        return major;
    }
};