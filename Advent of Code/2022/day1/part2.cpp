#include <iostream>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0;
    while (cin) {
        int sum = 0;
        string item;
        while (getline(cin, item) && !item.empty())
            sum += stoi(item);
        if (sum > a) {
            c = b;
            b = a;
            a = sum;
        } else if (sum > b) {
            c = b;
            b = sum;
        } else if (sum > c) {
            c = sum;
        }
    }
    cout << a + b + c << '\n';
}
