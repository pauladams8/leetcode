#include <iostream>

using namespace std;

int main() {
    int total = 0;
    char opponent, player;
    while (cin >> opponent >> player) {
        int playerScore = player - 'X', opponentScore = opponent - 'A';
        if (playerScore == (opponentScore + 1) % 3)
            playerScore += 6;
        else if (playerScore == opponentScore)
            playerScore += 3;
        total += playerScore + 1;
    }
    cout << total << '\n';
}
