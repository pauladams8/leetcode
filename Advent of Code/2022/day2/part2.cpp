#include <iostream>

using namespace std;

int main() {
    int total = 0;
    char opponent, outcome;
    while (cin >> opponent >> outcome) {
        int opponentScore = opponent - 'A';
        if (outcome == 'X')
            total += (opponentScore + 2) % 3 + 1;
        else if (outcome == 'Y')
            total += opponentScore + 4;
        else
            total += (opponentScore + 1) % 3 + 7;
    }
    cout << total << '\n';
}
