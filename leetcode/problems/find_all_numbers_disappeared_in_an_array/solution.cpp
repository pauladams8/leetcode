class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> appears(nums.size());
        for (int n : nums)
            appears[n - 1] = true;
        vector<int> disp;
        for (int i = 0; i < appears.size(); i++)
            if (!appears[i])
                disp.push_back(i + 1);
        return disp;
    }
};