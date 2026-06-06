#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void solve(string s) {
    int mask = 0;

    for (char c : s) {
        if (isalpha(c)) {          
            c = tolower(c);     
            mask |= (1 << (c - 'a'));
        }
    }

    if (mask == ((1 << 26) - 1))
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