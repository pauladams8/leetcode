#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 0;
    while (cin) {
        string as, bs, cs, ds;
        getline(cin, as, '-');
        getline(cin, bs, ',');
        getline(cin, cs, '-');
        getline(cin, ds, '\n');
        if (!cin) break;
        int a = stoi(as), b = stoi(bs), c = stoi(cs), d = stoi(ds);
        if (a <= d && c <= b)
            count++;
    }
    cout << count << '\n';
}