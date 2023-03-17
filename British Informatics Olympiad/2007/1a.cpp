#include <bits/stdc++.h>

using namespace std;

int sumTo(vector<int>& hand, int start, int n);

int main() {
    vector<int> hand(5);
    for (int i = 0; i < 5; i++)
        cin >> hand[i];
    int points = 0;
    vector<int> freq(11);
    for (int i = 0; i < 5; i++) {
        points += freq[hand[i]];
        freq[hand[i]]++;
    }
    points += sumTo(hand, 0, 15);
    cout << points << '\n';
}

int sumTo(vector<int>& hand, int start, int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = start; i < hand.size(); i++)
        count += sumTo(hand, i + 1, n - hand[i]);
    return count;
}