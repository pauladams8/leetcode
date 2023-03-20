class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            bool prevEmpty = i == 0 || flowerbed[i - 1] == 0;
            bool curEmpty = flowerbed[i] == 0;
            bool nextEmpty = i + 1 == flowerbed.size() || flowerbed[i + 1] == 0;
            if (prevEmpty && curEmpty && nextEmpty)
                n--, i++;
            if (n <= 0) return true;
        }
        return false;
    }
};