class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101);
        for (int h : heights)
            freq[h]++;
        int height = 0, count = 0;
        for (int h : heights) {
            while (freq[height] == 0)
                height++;
            if (h != height)
                count++;
            freq[height]--;
        }
        return count;
    }
};