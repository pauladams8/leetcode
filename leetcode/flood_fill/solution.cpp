class Solution {
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        floodFill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
private:
    void floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (sr < 0 || sr >= image.size()) return;
        if (sc < 0 || sc >= image[sr].size()) return;
        if (image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        floodFill(image, sr - 1, sc, oldColor, newColor);
        floodFill(image, sr, sc + 1, oldColor, newColor);
        floodFill(image, sr + 1, sc, oldColor, newColor);
        floodFill(image, sr, sc - 1, oldColor, newColor);
    }
};