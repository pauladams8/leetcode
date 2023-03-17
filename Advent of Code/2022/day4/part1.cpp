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
        if (a <= c && d <= b)
            count++;
        else if (c <= a && b <= d)
            count++;
    }
    cout << count << '\n';
}