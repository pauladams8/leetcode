class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        vector<int> ans1, ans2;
        for (int x : nums1) {
            if (set2.find(x) == set2.end()) {
                ans1.push_back(x);
                set2.insert(x);
            }
        }
        for (int x : nums2) {
            if (set1.find(x) == set1.end()) {
                ans2.push_back(x);
                set1.insert(x);
            }
        }
        return { ans1, ans2 };
    }
};