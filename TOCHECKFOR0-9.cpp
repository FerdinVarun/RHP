#include <iostream>
#include <string>
using namespace std;

void solve(string s) {
    int mask = 0;

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            mask |= (1 << (c - '0'));
        }
    }

    if (mask == ((1 << 10) - 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    solve(s);
    return 0;
}