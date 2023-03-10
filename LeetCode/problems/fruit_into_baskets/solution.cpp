class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, ans = 0;
        pair<int, int> firstPicked = { -1, -1 }, secondPicked = { -1, -1 };
        for (int end = 0; end < fruits.size(); end++) {
            if (firstPicked.first == fruits[end])
                swap(firstPicked, secondPicked), secondPicked.second = end;
            else if (secondPicked.first == fruits[end])
                secondPicked.second = end;
            else
                start = firstPicked.second + 1, firstPicked = secondPicked, secondPicked = { fruits[end], end };
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};