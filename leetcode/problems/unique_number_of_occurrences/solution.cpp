class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001);
        for (int n : arr)
            freq[n + 1000]++;
        vector<bool> seen(arr.size() + 1);
        for (int count : freq)
            if (count && seen[count])
                return false;
            else seen[count] = true;
        return true;
    }
};