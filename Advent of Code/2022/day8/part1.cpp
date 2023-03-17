#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& grid, int i, int j);
bool isVisible(vector<string>& grid, int i, int j);
bool isVisible(vector<string>& grid, int i, int j, int di, int dj);

vector<pair<int, int>> dir = {
    { -1, 0 },
    { 0, 1 },
    { 1, 0 },
    { 0, -1 }
};

int main() {
    vector<string> grid;
    string row;
    while (cin >> row)
        grid.push_back(row);
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (isVisible(grid, i, j))
                count++;
    cout << count << '\n';
}

bool isVisible(vector<string>& grid, int i, int j) {
    for (auto [di, dj] : dir)
        if (isVisible(grid, i, j, di, dj))
            return true;
    return false;
}

bool isVisible(vector<string>& grid, int i, int j, int di, int dj) {
    for (int ii = i, jj = j; isValid(grid, ii + di, jj + dj); ii += di, jj += dj)
        if (grid[ii + di][jj + dj] >= grid[i][j])
            return false;
    return true;
}

bool isValid(vector<string>& grid, int i, int j) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size();
}